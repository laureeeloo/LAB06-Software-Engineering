# Guía de Instalación Detallada

## Requisitos del Sistema

### Obligatorios
- **Sistema Operativo:** Linux o macOS
- **CMake:** Versión 3.10 o superior
- **Compilador C++:** Con soporte C++17
  - g++ 7.0+ (Linux)
  - clang 5.0+ (macOS/Linux)

### Verificar Requisitos Previos

#### 1. Verificar CMake
```bash
cmake --version
# Esperado: cmake version 3.10 o superior
```

#### 2. Verificar Compilador
```bash
g++ --version
# o
clang++ --version
# Esperado: versión 5.0 o superior
```

## Instalación en Linux

### Debian/Ubuntu
```bash
# Actualizar repositorios
sudo apt-get update

# Instalar CMake
sudo apt-get install cmake

# Instalar compilador (si no está instalado)
sudo apt-get install build-essential

# Instalar librerías estándar (generalmente ya incluidas)
sudo apt-get install libstdc++-13-dev
```

### Fedora/RHEL
```bash
# Instalar CMake y compilador
sudo dnf install cmake gcc-c++
```

### Arch Linux
```bash
# Instalar CMake y compilador
sudo pacman -S cmake gcc
```

## Instalación en macOS

### Con Homebrew
```bash
# Si no tienes Homebrew, instálalo primero
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Instalar CMake
brew install cmake

# Instalar compilador (Xcode Command Line Tools)
xcode-select --install
```

### Sin Homebrew (descarga manual)
- Descargar CMake desde https://cmake.org/download/
- Descargar Xcode Command Line Tools

## Proceso de Compilación

### Paso 1: Navegar al Directorio
```bash
cd "/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker"
```

### Paso 2: Hacer el Script Ejecutable
```bash
chmod +x build.sh
```

### Paso 3: Ejecutar la Compilación
```bash
./build.sh
```

**Lo que hace el script:**
1. Crea el directorio `build/`
2. Ejecuta `cmake ..` para configurar
3. Ejecuta `make` para compilar
4. Genera el ejecutable en `build/bin/habit_tracker`

### Paso 4: Verificar la Compilación
```bash
# Si ves este mensaje, la compilación fue exitosa:
# ✓ Compilación exitosa!
# ✓ Ejecutable: bin/habit_tracker

# Verificar que el ejecutable existe
ls -lh build/bin/habit_tracker
# Deberías ver un archivo de ~127 KB
```

## Ejecución

### Iniciar la Aplicación
```bash
./build/bin/habit_tracker
```

### Desde Cualquier Ubicación
```bash
# Crear un alias (opcional)
alias habit_tracker="/home/laura/Escriptori/3r\ carrera/Enginyeria\ de\ Software/Lab06/HabitTracker/build/bin/habit_tracker"

# Luego puedes ejecutar desde cualquier lugar
habit_tracker
```

## Compilación Manual (sin script)

Si prefieres compilar manualmente:

```bash
# Crear directorio de build
mkdir -p build
cd build

# Configurar con CMake
cmake ..

# Compilar
make

# Ejecutar
./bin/habit_tracker
```

## Opciones de Compilación

### Compilación en Modo Debug
```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

### Compilación Optimizada (Release)
```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Compilación Paralela (más rápida)
```bash
make -j4  # Usa 4 procesadores
```

### Compilación Verbosa (ver comandos)
```bash
make VERBOSE=1
```

## Limpiar la Compilación

### Borrar Build Anterior
```bash
rm -rf build
./build.sh  # Recompilará desde cero
```

### Limpiar Solo los Objetos (mantener Makefile)
```bash
cd build
make clean
make
```

## Solución de Problemas

### Problema: "cmake: command not found"
**Solución:**
```bash
# Instalar cmake (ver sección de instalación arriba)
# o especificar ruta completa
/usr/bin/cmake ..
```

### Problema: "error: expected ';' before '}' token"
**Solución:** El compilador no soporta C++17
```bash
# Instalar compilador más reciente
sudo apt-get install g++-11
# o
sudo apt-get install clang-13
```

### Problema: "No rule to make target 'bin/habit_tracker'"
**Solución:**
```bash
# Limpiar y recompilar
cd build
rm -rf *
cmake ..
make
```

### Problema: "Permission denied: ./build.sh"
**Solución:**
```bash
chmod +x build.sh
./build.sh
```

### Problema: "No such file or directory"
**Solución:**
```bash
# Usar ruta completa
cd "/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker"
# o
cd ~/Escriptori/"3r carrera"/"Enginyeria de Software"/Lab06/HabitTracker
```

## Instalación Global (Opcional)

### Copiar Ejecutable a /usr/local/bin
```bash
sudo cp build/bin/habit_tracker /usr/local/bin/
sudo chmod +x /usr/local/bin/habit_tracker

# Ahora puedes ejecutar desde cualquier lugar
habit_tracker
```

### Desinstalación
```bash
sudo rm /usr/local/bin/habit_tracker
```

## Documentación Adicional

- **README.md** - Guía de uso completa
- **QUICK_START.md** - Inicio rápido
- **ARCHITECTURE.md** - Detalles técnicos
- **TESTING.md** - Plan de pruebas

## Soporte

Para problemas durante la instalación:
1. Verifica que tienes CMake 3.10+
2. Verifica que tienes compilador C++17
3. Intenta compilación manual (sin script)
4. Revisa los archivos de error en `build/CMakeFiles/`

---

**¡Instalación completada! 🎉**
