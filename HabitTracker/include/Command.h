#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include <vector>

/**
 * @class Command
 * @brief Patrón Command para implementar funcionalidad de deshacer (Undo)
 * 
 * Define la interfaz para comandos que pueden ser ejecutados y deshechos.
 */
class Command {
public:
    virtual ~Command() = default;

    /**
     * @brief Ejecuta el comando
     */
    virtual void execute() = 0;

    /**
     * @brief Deshace el comando
     */
    virtual void undo() = 0;

    /**
     * @brief Obtiene una descripción del comando
     * @return Descripción del comando para mostrar al usuario
     */
    virtual std::string getDescription() const = 0;
};

/**
 * @class CommandHistory
 * @brief Gestiona el historial de comandos para implementar undo/redo
 */
class CommandHistory {
private:
    std::vector<std::shared_ptr<Command>> history;
    size_t currentIndex;

public:
    CommandHistory();

    /**
     * @brief Ejecuta un comando y lo añade al historial
     * @param command El comando a ejecutar
     */
    void execute(std::shared_ptr<Command> command);

    /**
     * @brief Deshace el último comando ejecutado
     * @return true si se pudo deshacer, false si no hay más comandos
     */
    bool undo();

    /**
     * @brief Verifica si hay comandos para deshacer
     * @return true si hay comandos para deshacer
     */
    bool canUndo() const;

    /**
     * @brief Limpia el historial
     */
    void clear();

    /**
     * @brief Obtiene el tamaño del historial
     * @return Número de comandos en el historial
     */
    size_t size() const;
};

#endif // COMMAND_H
