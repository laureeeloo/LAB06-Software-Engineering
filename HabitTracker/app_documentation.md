# HabitTracker - Aplicación de Seguimiento de Hábitos

Una aplicación C++ moderna para rastrear y gestionar tus hábitos personales con características avanzadas como deshacer, persistencia de datos y análisis de cumplimiento.

## 🎯 Características

✅ **Crear hábitos personales** - Define nuevos hábitos con nombre y descripción  
✅ **Marcar como completados** - Registra diariamente tus hábitos completados  
✅ **Calendario de cumplimiento** - Visualiza tu progreso con un calendario detallado  
✅ **Eliminar hábitos** - Gestiona tus hábitos eliminando los obsoletos  
✅ **Deshacer acciones (Undo)** - Revierte tus últimas acciones fácilmente  
✅ **Persistencia de datos** - Guarda y carga tus hábitos automáticamente  
✅ **Análisis de progreso** - Calcula porcentajes de cumplimiento y estadísticas  

## 🏗️ Arquitectura

### Estructura de Carpetas

```
HabitTracker/
├── include/              # Archivos header
│   ├── Habit.h          # Clase para representar un hábito
│   ├── Command.h        # Patrón Command para Undo
│   ├── HabitTracker.h   # Gestor principal de hábitos
│   └── FileManager.h    # Gestión de persistencia
├── src/                 # Implementación
│   ├── main.cpp        # Interfaz de usuario (CLI)
│   ├── Habit.cpp
│   ├── Command.cpp
│   ├── HabitTracker.cpp
│   └── FileManager.cpp
├── CMakeLists.txt      # Configuración de compilación
└── README.md           # Este archivo
```

### Componentes Principales

#### 1. **Habit.h**
Representa un hábito individual con:
- Nombre, descripción e ID único
- Calendario de cumplimiento (YYYY-MM-DD)
- Métodos para marcar completados/incompletos
- Cálculo de estadísticas de cumplimiento

#### 2. **Command.h**
Implementa el patrón Command para:
- Historial de comandos
- Funcionalidad de deshacer (Undo)
- Interfaz para comandos reversibles

#### 3. **HabitTracker.h**
Gestor central que proporciona:
- CRUD de hábitos
- Integración del patrón Command
- Queries sobre hábitos existentes

#### 4. **FileManager.h**
Persiste datos mediante:
- Serialización a archivo de texto
- Carga automática al iniciar
- Manejo seguro de errores

## 🚀 Compilación

### Requisitos

- CMake 3.10+
- Compilador C++17 (g++, clang, msvc)
- Linux, macOS o Windows

### Pasos de Compilación

```bash
cd HabitTracker
mkdir build
cd build
cmake ..
make
```

El ejecutable se generará en: `build/bin/habit_tracker`

## 💻 Uso

### Ejecutar la aplicación

```bash
./build/bin/habit_tracker
```

### Menú Principal

```
========================================================
         HABIT TRACKER - GESTIÓN DE HÁBITOS
========================================================
1. Crear nuevo hábito
2. Ver todos los hábitos
3. Marcar hábito como completado
4. Ver detalles de un hábito
5. Ver calendario de cumplimiento
6. Eliminar un hábito
7. Deshacer última acción
8. Guardar datos
9. Cargar datos
0. Salir
========================================================
```

### Ejemplos de Uso

**Crear un hábito:**
```
Selecciona una opción: 1
--- CREAR NUEVO HÁBITO ---
Nombre del hábito: Hacer ejercicio
Descripción del hábito: 30 minutos de cardio
✓ Hábito creado exitosamente!
ID del hábito: HABIT_1
```

**Marcar como completado:**
```
Selecciona una opción: 3
--- MARCAR HÁBITO COMO COMPLETADO ---
1. [HABIT_1] Hacer ejercicio
ID del hábito: HABIT_1
✓ Hábito marcado como completado para hoy (2026-05-27)
```

**Ver todos los hábitos:**
```
Selecciona una opción: 2
--- TODOS LOS HÁBITOS ---
1. [HABIT_1] Hacer ejercicio
   Descripción: 30 minutos de cardio
   Creado: 2026-05-27 14:32:15
   Días completados: 5
   Cumplimiento: 83.3%
```

## 📊 Cumplimiento de User Stories

### US-1: Definir Hábitos Personales
- ✅ Disponible en interfaz principal (opción 1)
- ✅ Undo disponible (opción 7)
- ✅ Confirmación del sistema
- ✅ Datos persistentes

### US-2: Marcar Hábitos Completados
- ✅ Disponible en interfaz principal (opción 3)
- ✅ Undo disponible (opción 7)
- ✅ Confirmación del sistema
- ✅ Datos persistentes

### US-3: Ver Calendario de Cumplimiento
- ✅ Disponible en interfaz principal (opción 5)
- ✅ Muestra todas las fechas registradas
- ✅ Visualiza estado completado/incompleto
- ✅ Calcula estadísticas

### US-4: Eliminar Hábitos
- ✅ Disponible en interfaz principal (opción 6)
- ✅ Undo disponible (opción 7)
- ✅ Confirmación de seguridad
- ✅ Datos persistentes

## 🔄 Persistencia de Datos

### Formato de Almacenamiento

Los hábitos se guardan en `habits_data.txt` en formato delimitado:

```
ID|Nombre|Descripción|Timestamp|Fecha1:Estado|Fecha2:Estado|...
```

Ejemplo:
```
HABIT_1|Hacer ejercicio|30 minutos de cardio|1716815535|2026-05-25:1|2026-05-26:0|2026-05-27:1
```

### Características de Persistencia

- **Auto-carga**: Al iniciar, carga automáticamente datos previos
- **Auto-guardado**: Opción manual (opción 8) o al salir
- **Tolerancia a errores**: Maneja líneas corruptas sin fallar
- **Backup**: Los datos antiguos se reemplazan sin riesgos

## 🎨 Calidad del Código

### Características de Diseño

✅ **Uso de patrones de diseño:**
- Command Pattern para Undo/Redo
- Separación de responsabilidades

✅ **Código limpio:**
- Nombres descriptivos
- Funciones documentadas con Doxygen
- Código modular y reutilizable

✅ **Optimizaciones:**
- Uso de smart pointers (std::shared_ptr)
- Referencias const donde es apropiado
- Evita copias innecesarias

✅ **Manejo de errores:**
- Try-catch en operaciones I/O
- Validaciones en entrada
- Mensajes de error informativos

## 📝 Documentación

El código incluye documentación completa en formato Doxygen:

```cpp
/**
 * @class Habit
 * @brief Representa un hábito personal que el usuario quiere rastrear
 */
```

Para generar documentación HTML:
```bash
doxygen Doxyfile
```

## 🚀 Mejoras Futuras

- [ ] Base de datos en lugar de archivos de texto
- [ ] Interfaz gráfica (GUI)
- [ ] Análisis estadístico avanzado
- [ ] Sincronización en la nube
- [ ] Recordatorios y notificaciones
- [ ] Exportar reportes en PDF
- [ ] Aplicación web

## 📄 Licencia

Este proyecto es código abierto bajo licencia MIT.

## 👨‍💻 Autor

Desarrollado como parte del laboratorio 06 de Ingeniería de Software.

---

**¡Disfruta rastreando tus hábitos! 🎯**
