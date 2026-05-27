#include "../include/HabitTracker.h"
#include <algorithm>

HabitTracker::HabitTracker() : nextHabitId(1) {}

std::string HabitTracker::generateHabitId() {
    return "HABIT_" + std::to_string(nextHabitId++);
}

// Implementación AddHabitCommand
HabitTracker::AddHabitCommand::AddHabitCommand(HabitTracker& t, const Habit& h)
    : tracker(t), habit(h), habitId(h.getId()) {}

void HabitTracker::AddHabitCommand::execute() {
    tracker.habits[habitId] = habit;
}

void HabitTracker::AddHabitCommand::undo() {
    tracker.habits.erase(habitId);
}

std::string HabitTracker::AddHabitCommand::getDescription() const {
    return "Added habit: " + habit.getName();
}

// Implementación DeleteHabitCommand
HabitTracker::DeleteHabitCommand::DeleteHabitCommand(HabitTracker& t, const std::string& id)
    : tracker(t), habitId(id) {
    auto it = tracker.habits.find(id);
    if (it != tracker.habits.end()) {
        savedHabit = it->second;
    }
}

void HabitTracker::DeleteHabitCommand::execute() {
    tracker.habits.erase(habitId);
}

void HabitTracker::DeleteHabitCommand::undo() {
    tracker.habits[habitId] = savedHabit;
}

std::string HabitTracker::DeleteHabitCommand::getDescription() const {
    return "Deleted habit: " + savedHabit.getName();
}

// Implementación MarkCompletedCommand
HabitTracker::MarkCompletedCommand::MarkCompletedCommand(HabitTracker& t, const std::string& id, const std::string& d)
    : tracker(t), habitId(id), date(d) {
    auto it = tracker.habits.find(id);
    if (it != tracker.habits.end()) {
        wasCompleted = it->second.isCompletedOn(date);
    }
}

void HabitTracker::MarkCompletedCommand::execute() {
    auto it = tracker.habits.find(habitId);
    if (it != tracker.habits.end()) {
        it->second.markAsCompleted(date);
    }
}

void HabitTracker::MarkCompletedCommand::undo() {
    auto it = tracker.habits.find(habitId);
    if (it != tracker.habits.end()) {
        if (wasCompleted) {
            it->second.markAsCompleted(date);
        } else {
            it->second.unmarkAsCompleted(date);
        }
    }
}

std::string HabitTracker::MarkCompletedCommand::getDescription() const {
    return "Marked habit as completed on " + date;
}

// Métodos públicos de HabitTracker
std::string HabitTracker::addHabit(const std::string& name, const std::string& description) {
    std::string id = generateHabitId();
    Habit newHabit(id, name, description);
    auto command = std::make_shared<AddHabitCommand>(*this, newHabit);
    commandHistory.execute(command);
    return id;
}

bool HabitTracker::deleteHabit(const std::string& habitId) {
    if (habits.find(habitId) == habits.end()) {
        return false;
    }
    auto command = std::make_shared<DeleteHabitCommand>(*this, habitId);
    commandHistory.execute(command);
    return true;
}

bool HabitTracker::markCompleted(const std::string& habitId, const std::string& date) {
    if (habits.find(habitId) == habits.end()) {
        return false;
    }
    auto command = std::make_shared<MarkCompletedCommand>(*this, habitId, date);
    commandHistory.execute(command);
    return true;
}

std::string HabitTracker::undoLastAction() {
    if (commandHistory.canUndo()) {
        std::string description = commandHistory.size() > 0 ? 
            "Action undone" : "No action to undo";
        commandHistory.undo();
        return description;
    }
    return "No action to undo";
}

std::vector<std::pair<std::string, const Habit*>> HabitTracker::getAllHabits() const {
    std::vector<std::pair<std::string, const Habit*>> result;
    for (const auto& entry : habits) {
        result.push_back({entry.first, &entry.second});
    }
    return result;
}

const Habit* HabitTracker::getHabit(const std::string& habitId) const {
    auto it = habits.find(habitId);
    if (it != habits.end()) {
        return &it->second;
    }
    return nullptr;
}

size_t HabitTracker::getHabitCount() const {
    return habits.size();
}

bool HabitTracker::canUndo() const {
    return commandHistory.canUndo();
}

void HabitTracker::clear() {
    habits.clear();
    commandHistory.clear();
    nextHabitId = 1;
}

void HabitTracker::loadHabit(const Habit& habit) {
    habits[habit.getId()] = habit;
}
