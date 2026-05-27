#ifndef HABIT_TRACKER_H
#define HABIT_TRACKER_H

#include "Habit.h"
#include "Command.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

/**
 * @class HabitTracker
 * @brief Gestor principal de hábitos
 * 
 * Proporciona funcionalidades para crear, actualizar, eliminar y consultar hábitos.
 * Implementa el patrón Command para soporte de deshacer.
 */
class HabitTracker {
private:
    std::map<std::string, Habit> habits;
    CommandHistory commandHistory;
    int nextHabitId;

    /**
     * @brief Genera un ID único para un nuevo hábito
     * @return ID único
     */
    std::string generateHabitId();
    void updateNextHabitIdFrom(const std::string& habitId);

    // Comandos internos
    class AddHabitCommand : public Command {
    private:
        HabitTracker& tracker;
        Habit habit;
        std::string habitId;

    public:
        AddHabitCommand(HabitTracker& t, const Habit& h);
        void execute() override;
        void undo() override;
        std::string getDescription() const override;
    };

    class DeleteHabitCommand : public Command {
    private:
        HabitTracker& tracker;
        std::string habitId;
        Habit savedHabit;

    public:
        DeleteHabitCommand(HabitTracker& t, const std::string& id);
        void execute() override;
        void undo() override;
        std::string getDescription() const override;
    };

    class MarkCompletedCommand : public Command {
    private:
        HabitTracker& tracker;
        std::string habitId;
        std::string date;
        bool wasCompleted;

    public:
        MarkCompletedCommand(HabitTracker& t, const std::string& id, const std::string& d);
        void execute() override;
        void undo() override;
        std::string getDescription() const override;
    };

public:
    HabitTracker();

    /**
     * @brief Añade un nuevo hábito
     * @param name Nombre del hábito
     * @param description Descripción del hábito
     * @return ID del hábito creado
     */
    std::string addHabit(const std::string& name, const std::string& description);

    /**
     * @brief Elimina un hábito existente
     * @param habitId ID del hábito a eliminar
     * @return true si se eliminó correctamente, false si no existe
     */
    bool deleteHabit(const std::string& habitId);

    /**
     * @brief Marca un hábito como completado en una fecha
     * @param habitId ID del hábito
     * @param date Fecha en formato YYYY-MM-DD
     * @return true si se completó, false si no existe el hábito
     */
    bool markCompleted(const std::string& habitId, const std::string& date);

    /**
     * @brief Deshace la última acción
     * @return Descripción de lo que se deshizo
     */
    std::string undoLastAction();

    /**
     * @brief Obtiene todos los hábitos
     * @return Vector con referencias a todos los hábitos
     */
    std::vector<std::pair<std::string, const Habit*>> getAllHabits() const;

    /**
     * @brief Obtiene un hábito por ID
     * @param habitId ID del hábito
     * @return Puntero al hábito, nullptr si no existe
     */
    const Habit* getHabit(const std::string& habitId) const;

    /**
     * @brief Obtiene el número de hábitos
     * @return Cantidad de hábitos
     */
    size_t getHabitCount() const;

    /**
     * @brief Verifica si hay acciones para deshacer
     * @return true si hay acciones para deshacer
     */
    bool canUndo() const;

    /**
     * @brief Limpia todos los hábitos
     */
    void clear();

    /**
     * @brief Carga un hábito directamente (para persistencia)
     * @param habit Hábito a cargar
     */
    void loadHabit(const Habit& habit);
};

#endif // HABIT_TRACKER_H
