#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "HabitTracker.h"
#include <string>

/**
 * @class FileManager
 * @brief Gestiona la persistencia de datos (guardar/cargar hábitos)
 * 
 * Proporciona funcionalidades para serializar y deserializar hábitos
 * a un archivo.
 */
class FileManager {
private:
    std::string filePath;

public:
    /**
     * @brief Constructor de FileManager
     * @param path Ruta del archivo de datos
     */
    explicit FileManager(const std::string& path);

    /**
     * @brief Guarda todos los hábitos en un archivo
     * @param tracker El rastreador de hábitos con los datos a guardar
     * @return true si se guardó correctamente, false en caso de error
     */
    bool saveHabits(const HabitTracker& tracker);

    /**
     * @brief Carga todos los hábitos desde el archivo
     * @param tracker El rastreador de hábitos donde cargar los datos
     * @return true si se cargó correctamente, false en caso de error
     */
    bool loadHabits(HabitTracker& tracker);

    /**
     * @brief Verifica si el archivo de datos existe
     * @return true si existe, false en caso contrario
     */
    bool fileExists() const;

    /**
     * @brief Elimina el archivo de datos
     * @return true si se eliminó correctamente, false en caso de error
     */
    bool deleteDataFile();

    /**
     * @brief Obtiene la ruta del archivo
     * @return Ruta del archivo de datos
     */
    std::string getFilePath() const;
};

#endif // FILE_MANAGER_H
