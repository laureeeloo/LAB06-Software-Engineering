#!/bin/bash

# Script de compilación para HabitTracker

# Colores
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  HabitTracker - Build Script${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Crear directorio de build si no existe
if [ ! -d "build" ]; then
    echo -e "${BLUE}[*] Creando directorio build...${NC}"
    mkdir build
fi

# Navegar a build
cd build

# Ejecutar CMake
echo -e "${BLUE}[*] Configurando CMake...${NC}"
cmake ..

if [ $? -ne 0 ]; then
    echo -e "${RED}[✗] Error en CMake${NC}"
    exit 1
fi

# Compilar
echo -e "${BLUE}[*] Compilando...${NC}"
make

if [ $? -ne 0 ]; then
    echo -e "${RED}[✗] Error en compilación${NC}"
    exit 1
fi

echo -e "${GREEN}[✓] Compilación exitosa!${NC}"
echo -e "${GREEN}[✓] Ejecutable: bin/habit_tracker${NC}\n"

# Regresar al directorio raíz
cd ..

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}Para ejecutar la aplicación:${NC}"
echo -e "${GREEN}  ./build/bin/habit_tracker${NC}"
echo -e "${BLUE}========================================${NC}\n"
