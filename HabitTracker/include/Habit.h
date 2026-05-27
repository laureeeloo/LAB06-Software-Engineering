#ifndef HABIT_H
#define HABIT_H

#include <string>
#include <vector>
#include <ctime>
#include <map>

/**
 * @class Habit
 * @brief Representa un hábito personal que el usuario quiere rastrear
 * 
 * Almacena información sobre un hábito, incluyendo su nombre, descripción,
 * fecha de creación y un calendario de cumplimiento.
 */
class Habit {
private:
    std::string id;
    std::string name;
    std::string description;
    time_t createdAt;
    std::map<std::string, bool> completionCalendar;  // YYYY-MM-DD -> completed

public:
    /**
     * @brief Constructor predeterminado de Habit
     */
    Habit() = default;

    /**
     * @brief Constructor de Habit
     * @param id Identificador único del hábito
     * @param name Nombre del hábito
     * @param description Descripción del hábito
     */
    Habit(const std::string& id, const std::string& name, const std::string& description);

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    time_t getCreatedAt() const;
    const std::map<std::string, bool>& getCompletionCalendar() const;

    // Métodos para completar un hábito
    /**
     * @brief Marca el hábito como completado en una fecha específica
     * @param date Fecha en formato YYYY-MM-DD
     */
    void markAsCompleted(const std::string& date);

    /**
     * @brief Desmarca el hábito en una fecha específica
     * @param date Fecha en formato YYYY-MM-DD
     */
    void unmarkAsCompleted(const std::string& date);

    /**
     * @brief Verifica si el hábito fue completado en una fecha específica
     * @param date Fecha en formato YYYY-MM-DD
     * @return true si fue completado, false en caso contrario
     */
    bool isCompletedOn(const std::string& date) const;

    /**
     * @brief Obtiene el total de días completados
     * @return Número de días completados
     */
    int getTotalCompletedDays() const;

    /**
     * @brief Calcula el porcentaje de cumplimiento desde la creación
     * @return Porcentaje de cumplimiento (0-100)
     */
    double getCompliancePercentage() const;

    /**
     * @brief Serializa el hábito a una cadena
     * @return Representación en string del hábito
     */
    std::string serialize() const;

    /**
     * @brief Deserializa un hábito desde una cadena
     * @param data Datos serializados
     * @return Objeto Habit deserializado
     */
    static Habit deserialize(const std::string& data);
};

#endif // HABIT_H
