#include "../include/FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

FileManager::FileManager(const std::string& path) : filePath(path) {}

bool FileManager::saveHabits(const HabitTracker& tracker) {
    try {
        std::ofstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file for writing: " << filePath << std::endl;
            return false;
        }

        auto habits = tracker.getAllHabits();
        for (const auto& entry : habits) {
            const Habit* habit = entry.second;
            if (habit) {
                file << habit->serialize() << "\n";
            }
        }

        file.close();
        std::cout << "✓ Data saved successfully to: " << filePath << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error saving habits: " << e.what() << std::endl;
        return false;
    }
}

bool FileManager::loadHabits(HabitTracker& tracker) {
    try {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file for reading: " << filePath << std::endl;
            return false;
        }

        tracker.clear();

        std::string line;
        int loadedCount = 0;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                try {
                    Habit habit = Habit::deserialize(line);
                    tracker.loadHabit(habit);
                    loadedCount++;
                } catch (const std::exception& e) {
                    std::cerr << "Warning: Could not load habit: " << e.what() << std::endl;
                }
            }
        }

        file.close();
        if (loadedCount > 0) {
            std::cout << "✓ " << loadedCount << " habit(s) loaded successfully" << std::endl;
        }
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error loading habits: " << e.what() << std::endl;
        return false;
    }
}

bool FileManager::fileExists() const {
    return std::filesystem::exists(filePath);
}

bool FileManager::deleteDataFile() {
    try {
        if (fileExists()) {
            std::filesystem::remove(filePath);
            return true;
        }
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error deleting file: " << e.what() << std::endl;
        return false;
    }
}

std::string FileManager::getFilePath() const {
    return filePath;
}
