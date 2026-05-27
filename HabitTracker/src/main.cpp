#include "include/HabitTracker.h"
#include "include/FileManager.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

/**
 * @brief Obtiene la fecha actual en formato YYYY-MM-DD
 * @return String con la fecha actual
 */
std::string getTodayDate() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm* timeInfo = std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(timeInfo, "%Y-%m-%d");
    return oss.str();
}

/**
 * @brief Convierte timestamp a fecha legible
 * @param timestamp Timestamp de Unix
 * @return String con fecha y hora
 */
std::string timestampToString(time_t timestamp) {
    std::tm* timeInfo = std::localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(timeInfo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

/**
 * @brief Muestra un separador visual
 */
void printSeparator(char ch = '=', int width = 60) {
    std::cout << std::string(width, ch) << std::endl;
}

/**
 * @brief Muestra el menú principal
 */
void displayMenu() {
    printSeparator();
    std::cout << "         HABIT TRACKER - GESTIÓN DE HÁBITOS" << std::endl;
    printSeparator();
    std::cout << "1. Crear nuevo hábito" << std::endl;
    std::cout << "2. Ver todos los hábitos" << std::endl;
    std::cout << "3. Marcar hábito como completado" << std::endl;
    std::cout << "4. Ver detalles de un hábito" << std::endl;
    std::cout << "5. Ver calendario de cumplimiento" << std::endl;
    std::cout << "6. Eliminar un hábito" << std::endl;
    std::cout << "7. Deshacer última acción" << std::endl;
    std::cout << "8. Guardar datos" << std::endl;
    std::cout << "9. Cargar datos" << std::endl;
    std::cout << "0. Salir" << std::endl;
    printSeparator();
    std::cout << "Selecciona una opción: ";
}

/**
 * @brief Crea un nuevo hábito de forma interactiva
 */
void createHabit(HabitTracker& tracker) {
    std::cout << "\n--- CREAR NUEVO HÁBITO ---" << std::endl;
    std::string name, description;

    std::cout << "Nombre del hábito: ";
    std::getline(std::cin, name);

    std::cout << "Descripción del hábito: ";
    std::getline(std::cin, description);

    if (!name.empty()) {
        std::string habitId = tracker.addHabit(name, description);
        std::cout << "\n✓ Hábito creado exitosamente!" << std::endl;
        std::cout << "ID del hábito: " << habitId << std::endl;
    } else {
        std::cout << "✗ Error: El nombre del hábito no puede estar vacío." << std::endl;
    }
}

/**
 * @brief Muestra todos los hábitos
 */
void viewAllHabits(const HabitTracker& tracker) {
    std::cout << "\n--- TODOS LOS HÁBITOS ---" << std::endl;

    auto habits = tracker.getAllHabits();
    if (habits.empty()) {
        std::cout << "No hay hábitos aún. ¡Crea uno!" << std::endl;
        return;
    }

    for (size_t i = 0; i < habits.size(); ++i) {
        const Habit* habit = habits[i].second;
        std::cout << "\n" << (i + 1) << ". [" << habits[i].first << "] " << habit->getName() << std::endl;
        std::cout << "   Descripción: " << habit->getDescription() << std::endl;
        std::cout << "   Creado: " << timestampToString(habit->getCreatedAt()) << std::endl;
        std::cout << "   Días completados: " << habit->getTotalCompletedDays() << std::endl;
        std::cout << "   Cumplimiento: " << std::fixed << std::setprecision(1) 
                  << habit->getCompliancePercentage() << "%" << std::endl;
    }
}

/**
 * @brief Marca un hábito como completado para hoy
 */
void markHabitCompleted(HabitTracker& tracker) {
    std::cout << "\n--- MARCAR HÁBITO COMO COMPLETADO ---" << std::endl;

    auto habits = tracker.getAllHabits();
    if (habits.empty()) {
        std::cout << "No hay hábitos disponibles." << std::endl;
        return;
    }

    std::cout << "Selecciona el ID del hábito a marcar como completado:" << std::endl;
    for (size_t i = 0; i < habits.size(); ++i) {
        std::cout << (i + 1) << ". [" << habits[i].first << "] " 
                  << habits[i].second->getName() << std::endl;
    }

    std::string habitId;
    std::cout << "ID del hábito: ";
    std::getline(std::cin, habitId);

    std::string today = getTodayDate();
    if (tracker.markCompleted(habitId, today)) {
        std::cout << "\n✓ Hábito marcado como completado para hoy (" << today << ")" << std::endl;
    } else {
        std::cout << "\n✗ Error: Hábito no encontrado." << std::endl;
    }
}

/**
 * @brief Muestra detalles de un hábito específico
 */
void viewHabitDetails(const HabitTracker& tracker) {
    std::cout << "\n--- DETALLES DEL HÁBITO ---" << std::endl;

    auto habits = tracker.getAllHabits();
    if (habits.empty()) {
        std::cout << "No hay hábitos disponibles." << std::endl;
        return;
    }

    std::cout << "Selecciona el ID del hábito:" << std::endl;
    for (size_t i = 0; i < habits.size(); ++i) {
        std::cout << (i + 1) << ". [" << habits[i].first << "] " 
                  << habits[i].second->getName() << std::endl;
    }

    std::string habitId;
    std::cout << "ID del hábito: ";
    std::getline(std::cin, habitId);

    const Habit* habit = tracker.getHabit(habitId);
    if (!habit) {
        std::cout << "\n✗ Error: Hábito no encontrado." << std::endl;
        return;
    }

    std::cout << "\n--- INFORMACIÓN DEL HÁBITO ---" << std::endl;
    std::cout << "ID: " << habit->getId() << std::endl;
    std::cout << "Nombre: " << habit->getName() << std::endl;
    std::cout << "Descripción: " << habit->getDescription() << std::endl;
    std::cout << "Creado: " << timestampToString(habit->getCreatedAt()) << std::endl;
    std::cout << "Días completados: " << habit->getTotalCompletedDays() << std::endl;
    std::cout << "Cumplimiento: " << std::fixed << std::setprecision(1) 
              << habit->getCompliancePercentage() << "%" << std::endl;
}

/**
 * @brief Muestra el calendario de cumplimiento de un hábito
 */
void viewComplianceCalendar(const HabitTracker& tracker) {
    std::cout << "\n--- CALENDARIO DE CUMPLIMIENTO ---" << std::endl;

    auto habits = tracker.getAllHabits();
    if (habits.empty()) {
        std::cout << "No hay hábitos disponibles." << std::endl;
        return;
    }

    std::cout << "Selecciona el ID del hábito:" << std::endl;
    for (size_t i = 0; i < habits.size(); ++i) {
        std::cout << (i + 1) << ". [" << habits[i].first << "] " 
                  << habits[i].second->getName() << std::endl;
    }

    std::string habitId;
    std::cout << "ID del hábito: ";
    std::getline(std::cin, habitId);

    const Habit* habit = tracker.getHabit(habitId);
    if (!habit) {
        std::cout << "\n✗ Error: Hábito no encontrado." << std::endl;
        return;
    }

    std::cout << "\n--- CALENDARIO: " << habit->getName() << " ---" << std::endl;
    
    const auto& calendar = habit->getCompletionCalendar();
    if (calendar.empty()) {
        std::cout << "No hay registros de cumplimiento aún." << std::endl;
        return;
    }

    for (const auto& entry : calendar) {
        std::string status = entry.second ? "✓ COMPLETADO" : "✗ NO COMPLETADO";
        std::cout << entry.first << ": " << status << std::endl;
    }

    std::cout << "\nTotal completado: " << habit->getTotalCompletedDays() << " de " 
              << calendar.size() << " días" << std::endl;
}

/**
 * @brief Elimina un hábito
 */
void deleteHabit(HabitTracker& tracker) {
    std::cout << "\n--- ELIMINAR HÁBITO ---" << std::endl;

    auto habits = tracker.getAllHabits();
    if (habits.empty()) {
        std::cout << "No hay hábitos disponibles." << std::endl;
        return;
    }

    std::cout << "Selecciona el ID del hábito a eliminar:" << std::endl;
    for (size_t i = 0; i < habits.size(); ++i) {
        std::cout << (i + 1) << ". [" << habits[i].first << "] " 
                  << habits[i].second->getName() << std::endl;
    }

    std::string habitId;
    std::cout << "ID del hábito: ";
    std::getline(std::cin, habitId);

    std::string confirm;
    std::cout << "\n⚠ ¿Estás seguro de que quieres eliminar este hábito? (s/n): ";
    std::getline(std::cin, confirm);

    if (confirm == "s" || confirm == "S") {
        if (tracker.deleteHabit(habitId)) {
            std::cout << "\n✓ Hábito eliminado exitosamente." << std::endl;
        } else {
            std::cout << "\n✗ Error: No se pudo eliminar el hábito." << std::endl;
        }
    } else {
        std::cout << "Operación cancelada." << std::endl;
    }
}

/**
 * @brief Deshace la última acción
 */
void undoLastAction(HabitTracker& tracker) {
    if (tracker.canUndo()) {
        std::string message = tracker.undoLastAction();
        std::cout << "\n✓ Última acción deshecha." << std::endl;
        std::cout << message << std::endl;
    } else {
        std::cout << "\n✗ No hay acciones para deshacer." << std::endl;
    }
}

/**
 * @brief Guarda los datos en un archivo
 */
void saveData(const HabitTracker& tracker, FileManager& fileManager) {
    if (fileManager.saveHabits(tracker)) {
        std::cout << "\n✓ Datos guardados exitosamente." << std::endl;
    } else {
        std::cout << "\n✗ Error al guardar los datos." << std::endl;
    }
}

/**
 * @brief Carga los datos desde un archivo
 */
void loadData(HabitTracker& tracker, FileManager& fileManager) {
    if (fileManager.loadHabits(tracker)) {
        std::cout << "\n✓ Datos cargados exitosamente." << std::endl;
    } else {
        std::cout << "\n✗ Error al cargar los datos." << std::endl;
    }
}

/**
 * @brief Función principal
 */
int main() {
    HabitTracker tracker;
    FileManager fileManager("habits_data.txt");

    // Cargar datos existentes al iniciar
    if (fileManager.fileExists()) {
        fileManager.loadHabits(tracker);
    }

    std::string choice;
    bool running = true;

    while (running) {
        displayMenu();
        std::getline(std::cin, choice);

        switch (choice[0]) {
            case '1':
                createHabit(tracker);
                break;
            case '2':
                viewAllHabits(tracker);
                break;
            case '3':
                markHabitCompleted(tracker);
                break;
            case '4':
                viewHabitDetails(tracker);
                break;
            case '5':
                viewComplianceCalendar(tracker);
                break;
            case '6':
                deleteHabit(tracker);
                break;
            case '7':
                undoLastAction(tracker);
                break;
            case '8':
                saveData(tracker, fileManager);
                break;
            case '9':
                loadData(tracker, fileManager);
                break;
            case '0': {
                std::cout << "\n¿Deseas guardar antes de salir? (s/n): ";
                std::string saveChoice;
                std::getline(std::cin, saveChoice);
                if (saveChoice == "s" || saveChoice == "S") {
                    saveData(tracker, fileManager);
                }
                std::cout << "\n¡Hasta luego!" << std::endl;
                running = false;
                break;
            }
            default:
                std::cout << "\n✗ Opción no válida. Por favor, intenta de nuevo." << std::endl;
        }
    }

    return 0;
}
