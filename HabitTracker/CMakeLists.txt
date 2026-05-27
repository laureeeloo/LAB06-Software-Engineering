cmake_minimum_required(VERSION 3.10)
project(HabitTracker)

# Configurar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# Incluir directorios
include_directories(${PROJECT_SOURCE_DIR})

# Archivos fuente
set(SOURCES
    src/main.cpp
    src/Habit.cpp
    src/Command.cpp
    src/HabitTracker.cpp
    src/FileManager.cpp
)

# Headers
set(HEADERS
    include/Habit.h
    include/Command.h
    include/HabitTracker.h
    include/FileManager.h
)

# Crear el ejecutable
add_executable(habit_tracker ${SOURCES} ${HEADERS})

# Enlazar librerías de sistema si es necesario
if(UNIX)
    target_link_libraries(habit_tracker PRIVATE stdc++fs)
endif()

# Configurar para que el ejecutable se genere en la raíz del proyecto
set_target_properties(habit_tracker PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
