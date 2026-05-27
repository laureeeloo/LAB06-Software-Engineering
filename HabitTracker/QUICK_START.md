# Guía de Inicio Rápido - HabitTracker

## 📋 Requisitos Previos

- CMake 3.10+
- Compilador C++17 (g++, clang)
- Linux o macOS

## 🚀 Instalación Rápida

### 1. Compilar la Aplicación

```bash
cd "/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker"
chmod +x build.sh
./build.sh
```

**Resultado esperado:**
- Se creará una carpeta `build/`
- Se generará el ejecutable en `build/bin/habit_tracker`

### 2. Ejecutar la Aplicación

```bash
./build/bin/habit_tracker
```

## 💡 Ejemplos de Uso Básicos

### Crear un Nuevo Hábito

```
Opción: 1
Nombre del hábito: Meditar
Descripción del hábito: 10 minutos de meditación diaria
✓ Hábito creado exitosamente!
ID del hábito: HABIT_1
```

### Ver Todos los Hábitos

```
Opción: 2
--- TODOS LOS HÁBITOS ---
1. [HABIT_1] Meditar
   Descripción: 10 minutos de meditación diaria
   Creado: 2026-05-27 18:20:55
   Días completados: 0
   Cumplimiento: 0.0%
```

### Marcar Hábito como Completado

```
Opción: 3
ID del hábito: HABIT_1
✓ Hábito marcado como completado para hoy (2026-05-27)
```

### Ver Detalles de un Hábito

```
Opción: 4
ID del hábito: HABIT_1
--- INFORMACIÓN DEL HÁBITO ---
ID: HABIT_1
Nombre: Meditar
Descripción: 10 minutos de meditación diaria
Creado: 2026-05-27 18:20:55
Días completados: 1
Cumplimiento: 100.0%
```

### Ver Calendario de Cumplimiento

```
Opción: 5
ID del hábito: HABIT_1
--- CALENDARIO: Meditar ---
2026-05-27: ✓ COMPLETADO
Total completado: 1 de 1 días
```

### Deshacer Última Acción

```
Opción: 7
✓ Última acción deshecha.
```

### Guardar Datos

```
Opción: 8
✓ Datos guardados exitosamente a: habits_data.txt
```

## 📊 Cumplimiento de Requisitos

### User Story 1: Definir Hábitos Personales
- ✅ Crear hábitos con nombre y descripción
- ✅ Undo disponible
- ✅ Confirmación del sistema
- ✅ Datos persistentes

### User Story 2: Marcar Hábitos Completados
- ✅ Marcar diariamente
- ✅ Undo disponible
- ✅ Confirmación del sistema
- ✅ Datos persistentes

### User Story 3: Ver Calendario de Cumplimiento
- ✅ Visualización de fechas
- ✅ Estado completado/incompleto
- ✅ Estadísticas de cumplimiento

### User Story 4: Eliminar Hábitos
- ✅ Eliminar hábitos antiguos
- ✅ Undo disponible
- ✅ Confirmación de seguridad
- ✅ Datos persistentes

## 🔧 Personalización

### Cambiar Ubicación del Archivo de Datos

En `src/main.cpp`, línea ~350:
```cpp
FileManager fileManager("ruta/a/archivo.txt");
```

### Compilación con Optimizaciones

```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## 🐛 Solución de Problemas

### Error: "No such file or directory"
```bash
# Asegúrate de estar en el directorio correcto
cd "/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker"
```

### CMake no encuentra los archivos
```bash
# Elimina el directorio build y compila nuevamente
rm -rf build
./build.sh
```

### Error de permisos al ejecutar build.sh
```bash
chmod +x build.sh
```

## 📚 Documentación Completa

Ver [README.md](README.md) para documentación detallada.

## 📝 Archivos de Datos

- **Ubicación:** `habits_data.txt` (en el directorio donde se ejecuta la aplicación)
- **Formato:** Texto delimitado
- **Se crea automáticamente** al guardar datos

## ✨ Características Destacadas

- 🎯 Interfaz intuitiva en línea de comandos
- 💾 Persistencia automática de datos
- ⏮️ Sistema de deshacer (Undo) completo
- 📊 Cálculo automático de porcentaje de cumplimiento
- 🛡️ Manejo robusto de errores
- 📈 Estadísticas detalladas

---

**¿Necesitas ayuda?** Consulta README.md para más información.
