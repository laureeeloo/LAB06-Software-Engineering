#include "../include/Habit.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>

Habit::Habit(const std::string& id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description) {
    createdAt = std::time(nullptr);
}

std::string Habit::getId() const {
    return id;
}

std::string Habit::getName() const {
    return name;
}

std::string Habit::getDescription() const {
    return description;
}

time_t Habit::getCreatedAt() const {
    return createdAt;
}

const std::map<std::string, bool>& Habit::getCompletionCalendar() const {
    return completionCalendar;
}

void Habit::markAsCompleted(const std::string& date) {
    completionCalendar[date] = true;
}

void Habit::unmarkAsCompleted(const std::string& date) {
    completionCalendar[date] = false;
}

bool Habit::isCompletedOn(const std::string& date) const {
    auto it = completionCalendar.find(date);
    if (it != completionCalendar.end()) {
        return it->second;
    }
    return false;
}

int Habit::getTotalCompletedDays() const {
    int count = 0;
    for (const auto& entry : completionCalendar) {
        if (entry.second) {
            count++;
        }
    }
    return count;
}

double Habit::getCompliancePercentage() const {
    if (completionCalendar.empty()) {
        return 0.0;
    }

    int completed = getTotalCompletedDays();
    return (static_cast<double>(completed) / completionCalendar.size()) * 100.0;
}

std::string Habit::serialize() const {
    std::ostringstream oss;

    // Formato: ID|Name|Description|CreatedAt|Date1:bool|Date2:bool|...
    oss << id << "|" << name << "|" << description << "|" << createdAt;

    for (const auto& entry : completionCalendar) {
        oss << "|" << entry.first << ":" << (entry.second ? "1" : "0");
    }

    return oss.str();
}

Habit Habit::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(iss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() < 4) {
        throw std::invalid_argument("Invalid habit data format");
    }

    Habit habit(tokens[0], tokens[1], tokens[2]);
    habit.createdAt = std::stol(tokens[3]);

    // Cargar el calendario de cumplimiento
    for (size_t i = 4; i < tokens.size(); ++i) {
        size_t colonPos = tokens[i].find(':');
        if (colonPos != std::string::npos) {
            std::string date = tokens[i].substr(0, colonPos);
            bool completed = tokens[i].substr(colonPos + 1) == "1";
            habit.completionCalendar[date] = completed;
        }
    }

    return habit;
}
