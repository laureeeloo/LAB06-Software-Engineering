# 📚 Índice de Documentación - HabitTracker

## Bienvenida

¡Bienvenido al proyecto **HabitTracker**! Este índice te ayudará a navegar toda la documentación.

---

## 🚀 Para Empezar Rápidamente

**Si quieres empezar ahora mismo:**
1. Lee: [QUICK_START.md](QUICK_START.md) (5 minutos)
2. Sigue: [Compilación Rápida](#compilación-rápida)
3. Ejecuta: `./build/bin/habit_tracker`

---

## 📖 Documentación Principal

### [README.md](README.md) - Guía Completa
**Contenido:**
- Características principales
- Requisitos del sistema
- Pasos de compilación detallados
- Ejemplos de uso
- Cumplimiento de user stories

**Cuándo leerlo:** Primera vez usando la aplicación

---

### [QUICK_START.md](QUICK_START.md) - Inicio Rápido
**Contenido:**
- Instalación en 3 pasos
- Ejemplos prácticos de cada opción
- Casos de uso comunes
- Solución rápida de problemas

**Cuándo leerlo:** Tienes prisa y quieres empezar

---

### [INSTALL.md](INSTALL.md) - Guía de Instalación
**Contenido:**
- Verificación de requisitos
- Instalación en Linux, macOS
- Compilación manual
- Opciones avanzadas
- Solución de problemas de instalación

**Cuándo leerlo:** Tienes problemas durante la compilación

---

### [ARCHITECTURE.md](ARCHITECTURE.md) - Diseño Técnico
**Contenido:**
- Arquitectura general del proyecto
- Descripción de componentes
- Patrones de diseño aplicados
- Principios SOLID
- Flujos de operaciones
- Complejidad de algoritmos

**Cuándo leerlo:** Quieres entender el código profundamente

---

### [TESTING.md](TESTING.md) - Plan de Pruebas
**Contenido:**
- Matriz de pruebas para cada user story
- Procedimientos de prueba detallados
- Casos de prueba de integración
- Pruebas de robustez
- Resultados de validación

**Cuándo leerlo:** Quieres validar que todo funciona correctamente

---

### [SUMMARY.md](SUMMARY.md) - Resumen Ejecutivo
**Contenido:**
- Información general del proyecto
- Cumplimiento de requisitos
- Estadísticas del código
- Características destacadas
- Conclusiones

**Cuándo leerlo:** Necesitas una visión general rápida

---

## 📁 Estructura del Proyecto

```
HabitTracker/
├── include/                 # Interfaces (Headers)
│   ├── Habit.h             # Clase Habit
│   ├── Command.h           # Patrón Command
│   ├── HabitTracker.h      # Gestor principal
│   └── FileManager.h       # Persistencia
│
├── src/                    # Implementación
│   ├── main.cpp           # CLI
│   ├── Habit.cpp
│   ├── Command.cpp
│   ├── HabitTracker.cpp
│   └── FileManager.cpp
│
├── build/                  # Compilación (generado)
│   └── bin/
│       └── habit_tracker   # Ejecutable ✓
│
└── Documentación
    ├── README.md          # Guía completa
    ├── QUICK_START.md     # Inicio rápido
    ├── INSTALL.md         # Instalación
    ├── ARCHITECTURE.md    # Diseño técnico
    ├── TESTING.md         # Plan de pruebas
    ├── SUMMARY.md         # Resumen
    └── INDEX.md           # Este archivo
```

---

## 🔧 Compilación Rápida

### En 3 Comandos:
```bash
cd "/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker"
./build.sh
./build/bin/habit_tracker
```

### Detalles:
```bash
# 1. Entrar al directorio
cd "/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker"

# 2. Compilar
chmod +x build.sh
./build.sh

# 3. Ejecutar
./build/bin/habit_tracker
```

---

## 📝 Guía por Casos de Uso

### "Quiero usar la aplicación"
1. Lee: [QUICK_START.md](QUICK_START.md)
2. Sigue: [Compilación Rápida](#compilación-rápida)
3. Ve a: Menu principal → Opción 1 (Crear hábito)

### "Tengo problemas de instalación"
1. Lee: [INSTALL.md](INSTALL.md)
2. Busca tu error en "Solución de Problemas"
3. Si no lo encuentras, verifica CMake y compilador

### "Quiero entender el código"
1. Lee: [ARCHITECTURE.md](ARCHITECTURE.md)
2. Explora: `include/` → `src/`
3. Busca patrones de diseño en el código

### "Quiero validar que funciona"
1. Lee: [TESTING.md](TESTING.md)
2. Sigue los procedimientos de prueba
3. Verifica la matriz de cobertura

### "Necesito una visión general"
1. Lee: [SUMMARY.md](SUMMARY.md)
2. Revisa: Estadísticas y cumplimiento de requisitos

---

## 🎯 Características Principales

### ✅ Crear Hábitos
```bash
Opción 1 → Ingresar nombre → Ingresar descripción
```

### ✅ Marcar Completado
```bash
Opción 3 → Seleccionar hábito → Se marca con fecha de hoy
```

### ✅ Ver Calendario
```bash
Opción 5 → Seleccionar hábito → Ver fechas con estado
```

### ✅ Eliminar Hábito
```bash
Opción 6 → Seleccionar hábito → Confirmar → Se elimina
```

### ✅ Deshacer Acción
```bash
Opción 7 → Se revierte la última acción
```

---

## 🔍 Mapa de Conceptos

### User Stories
- **US-1:** Definir hábitos personales
- **US-2:** Marcar como completados
- **US-3:** Ver calendario de cumplimiento
- **US-4:** Eliminar hábitos

### Patrones de Diseño
- **Command Pattern:** Para Undo/Redo
- **Facade Pattern:** HabitTracker como interfaz
- **Strategy Pattern:** FileManager para persistencia

### Principios SOLID
- **S**ingle Responsibility
- **O**pen/Closed
- **L**iskov Substitution
- **I**nterface Segregation
- **D**ependency Inversion

---

## 📊 Estadísticas del Proyecto

| Métrica | Valor |
|---------|-------|
| Líneas de código | ~1,190 |
| Clases | 6 |
| User Stories | 4/4 |
| Criterios aceptación | 100% |
| Ejecutable | 127 KB |
| Documentación | 6 archivos |

---

## ✅ Checklist de Validación

Antes de usar la aplicación:
- [ ] He leído QUICK_START.md
- [ ] He compilado exitosamente
- [ ] He ejecutado la aplicación
- [ ] He creado un hábito de prueba
- [ ] He marcado como completado
- [ ] He guardado los datos

Antes de estudiar el código:
- [ ] He leído ARCHITECTURE.md
- [ ] He explorado la estructura del proyecto
- [ ] He identificado los patrones de diseño
- [ ] He entendido la responsabilidad de cada clase

---

## 🔗 Enlaces Rápidos

| Documento | Propósito |
|-----------|----------|
| [README.md](README.md) | Guía de uso completa |
| [QUICK_START.md](QUICK_START.md) | Empezar en 5 minutos |
| [INSTALL.md](INSTALL.md) | Compilación y instalación |
| [ARCHITECTURE.md](ARCHITECTURE.md) | Entender el diseño |
| [TESTING.md](TESTING.md) | Validar funcionamiento |
| [SUMMARY.md](SUMMARY.md) | Resumen ejecutivo |

---

## 🆘 Soporte Rápido

### Problema: No me compila
**Solución:** Ve a [INSTALL.md](INSTALL.md) → Solución de Problemas

### Problema: No sé cómo usar
**Solución:** Ve a [QUICK_START.md](QUICK_START.md)

### Problema: Quiero entender el código
**Solución:** Ve a [ARCHITECTURE.md](ARCHITECTURE.md)

### Problema: Quiero validar todo
**Solución:** Ve a [TESTING.md](TESTING.md)

---

## 📞 Información de Contacto

**Proyecto:** HabitTracker v1.0  
**Ubicación:** `/home/laura/Escriptori/3r carrera/Enginyeria de Software/Lab06/HabitTracker/`  
**Lenguaje:** C++17  
**Compilador:** g++ 13.3.0  
**Fecha:** Mayo 2026  

---

## 🎉 ¡Estás Listo!

Elige por dónde quieres empezar:

1. **Quiero usar ya** → [QUICK_START.md](QUICK_START.md)
2. **Quiero instalar** → [INSTALL.md](INSTALL.md)
3. **Quiero aprender** → [ARCHITECTURE.md](ARCHITECTURE.md)
4. **Quiero validar** → [TESTING.md](TESTING.md)
5. **Quiero todo** → [README.md](README.md)

---

**Última actualización:** 27 de mayo de 2026
