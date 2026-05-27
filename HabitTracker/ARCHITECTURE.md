# Arquitectura y Diseño de HabitTracker

## 🏗️ Arquitectura General

HabitTracker sigue una arquitectura modular y escalable utilizando principios SOLID:

```
┌─────────────────────────────────────┐
│        Interface de Usuario (CLI)    │
│         main.cpp                     │
└────────────┬────────────────────────┘
             │
┌────────────▼────────────────────────┐
│       HabitTracker (Gestor)         │
│      - Gestión de Hábitos           │
│      - Patrón Command (Undo/Redo)   │
└────────────┬───────────┬────────────┘
             │           │
    ┌────────▼──────┐  ┌─▼────────────┐
    │  Habit Class  │  │ Command Hist │
    │ - Datos       │  │ - Undo/Redo  │
    │ - Calendario  │  │              │
    └───────────────┘  └──────────────┘
             │
┌────────────▼────────────────────────┐
│      FileManager (Persistencia)     │
│  - Serialización                    │
│  - Deserialización                  │
└────────────┬────────────────────────┘
             │
    ┌────────▼───────────┐
    │  habits_data.txt    │
    │  (Almacenamiento)   │
    └─────────────────────┘
```

## 📦 Componentes Principales

### 1. **Habit.h / Habit.cpp**

**Responsabilidad:** Representar y gestionar un hábito individual

**Atributos:**
- `id`: Identificador único
- `name`: Nombre del hábito
- `description`: Descripción
- `createdAt`: Timestamp de creación
- `completionCalendar`: Mapa de fechas → estado

**Métodos Clave:**
- `markAsCompleted(date)`: Marca como completado
- `getCompliancePercentage()`: Calcula porcentaje
- `serialize()`: Convierte a string
- `deserialize()`: Reconstruye desde string

**Patrones Aplicados:**
- Encapsulación: Atributos privados
- Métodos de acceso: Getters para lectura

### 2. **Command.h / Command.cpp**

**Responsabilidad:** Implementar el patrón Command para Undo

**Clases:**
- `Command`: Interfaz abstracta
  - `execute()`: Ejecutar comando
  - `undo()`: Deshacer comando
  
- `CommandHistory`: Historial de comandos
  - `execute()`: Ejecuta y almacena
  - `undo()`: Deshace último
  - `canUndo()`: Verifica disponibilidad

**Patrones Aplicados:**
- **Command Pattern**: Encapsula acciones como objetos
- **History Pattern**: Mantiene registro de operaciones

### 3. **HabitTracker.h / HabitTracker.cpp**

**Responsabilidad:** Gestor central de hábitos

**Características Clave:**
- Gestión CRUD de hábitos
- Integración del patrón Command
- Generación de IDs únicos

**Comandos Internos:**
```cpp
- AddHabitCommand
- DeleteHabitCommand
- MarkCompletedCommand
```

**Métodos Públicos:**
```cpp
string addHabit(name, description)
bool deleteHabit(id)
bool markCompleted(id, date)
string undoLastAction()
vector<Habit> getAllHabits()
```

**Patrones Aplicados:**
- **Facade Pattern**: Interfaz simplificada
- **Command Pattern**: Operaciones reversibles

### 4. **FileManager.h / FileManager.cpp**

**Responsabilidad:** Persistencia de datos

**Métodos:**
```cpp
bool saveHabits(tracker)      // Guardar a archivo
bool loadHabits(tracker)      // Cargar desde archivo
bool fileExists()              // Verificar existencia
```

**Formato de Almacenamiento:**
```
ID|Name|Description|CreatedAt|Date1:Status|Date2:Status|...
```

**Ejemplo:**
```
HABIT_1|Meditar|10 min meditación|1716815535|2026-05-27:1|2026-05-28:0
```

**Patrones Aplicados:**
- **Strategy Pattern**: Encapsula serialización
- **Singleton-like**: Acceso centralizado a archivos

## 🔄 Flujo de Operaciones

### Crear un Hábito

```
1. Usuario selecciona opción 1
2. Ingresa nombre y descripción
3. HabitTracker.addHabit() es llamado
4. Se crea AddHabitCommand
5. CommandHistory.execute() agrega a historial
6. Hábito se almacena en map
7. Se muestra confirmación
```

### Marcar Completado

```
1. Usuario selecciona opción 3
2. Selecciona ID del hábito
3. HabitTracker.markCompleted() es llamado
4. Se crea MarkCompletedCommand
5. CommandHistory.execute() agrega a historial
6. Hábito.markAsCompleted(today) es llamado
7. Se muestra confirmación
```

### Deshacer Acción

```
1. Usuario selecciona opción 7
2. Si CommandHistory.canUndo():
   - Se obtiene último comando
   - Se llama command.undo()
   - Se muestra confirmación
3. Si no hay más comandos:
   - Se muestra "No hay acciones para deshacer"
```

## 💾 Gestión de Memoria

### Smart Pointers
```cpp
std::shared_ptr<Command> command = std::make_shared<AddHabitCommand>(...);
```

### Evitar Copias Innecesarias
```cpp
const Habit* getHabit(const string& id) const;  // Retorna referencia constante
```

### Contenedores Eficientes
```cpp
std::map<string, Habit>              // O(log n) búsqueda
std::vector<shared_ptr<Command>>     // Crecimiento dinámico
```

## 🎯 Principios SOLID Aplicados

### S - Single Responsibility Principle
- `Habit`: Solo representa un hábito
- `Command`: Solo encapsula una acción
- `FileManager`: Solo maneja persistencia

### O - Open/Closed Principle
- `Command` es abierto para extensión (nuevos comandos)
- Cerrado para modificación (interfaz estable)

### L - Liskov Substitution Principle
- Cualquier `Command` puede usarse en `CommandHistory`
- No hay violaciones de contrato

### I - Interface Segregation Principle
- `Command` interfaz mínima (execute, undo)
- `HabitTracker` interfaz clara y enfocada

### D - Dependency Inversion Principle
- Clases de alto nivel (HabitTracker) dependen de abstracciones (Command)
- No de implementaciones concretas

## 🔒 Manejo de Errores

### Try-Catch en I/O
```cpp
try {
    std::ofstream file(filePath);
    if (!file.is_open()) throw runtime_error("Cannot open file");
} catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
}
```

### Validaciones en Entrada
```cpp
if (habits.find(habitId) == habits.end()) {
    return false;  // Hábito no existe
}
```

## 📈 Complejidad de Operaciones

| Operación | Complejidad | Nota |
|-----------|------------|------|
| Crear hábito | O(log n) | Inserción en map |
| Eliminar hábito | O(log n) | Búsqueda en map |
| Obtener hábito | O(log n) | Búsqueda en map |
| Marcar completado | O(log n) | Acceso a calendario |
| Deshacer | O(1) | Acceso a último comando |
| Guardar | O(n) | Recorre todos hábitos |
| Cargar | O(n log n) | Inserta n en map |

## 🚀 Mejoras Futuras

### Corto Plazo
- [ ] Validación más robusta de fechas
- [ ] Búsqueda de hábitos por nombre
- [ ] Exportar estadísticas a CSV

### Mediano Plazo
- [ ] SQLite para base de datos
- [ ] Interfaz gráfica (Qt, wxWidgets)
- [ ] Sincronización en la nube

### Largo Plazo
- [ ] Aplicación móvil
- [ ] API REST
- [ ] Análisis de datos avanzado

## 📝 Documentación de Código

Todo el código incluye comentarios Doxygen:

```cpp
/**
 * @brief Descripción de la función
 * @param param Descripción del parámetro
 * @return Descripción del retorno
 */
```

Para generar documentación HTML:
```bash
doxygen Doxyfile
```

---

**Conclusión:** HabitTracker demuestra una arquitectura limpia, modular y escalable siguiendo principios de ingeniería de software profesional.
