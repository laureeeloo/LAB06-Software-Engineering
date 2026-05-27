#include "../include/Command.h"

CommandHistory::CommandHistory() : currentIndex(0) {}

void CommandHistory::execute(std::shared_ptr<Command> command) {
    if (command) {
        command->execute();
        history.erase(history.begin() + currentIndex, history.end());
        history.push_back(command);
        currentIndex++;
    }
}

bool CommandHistory::undo() {
    if (currentIndex > 0) {
        currentIndex--;
        history[currentIndex]->undo();
        return true;
    }
    return false;
}

bool CommandHistory::canUndo() const {
    return currentIndex > 0;
}

void CommandHistory::clear() {
    history.clear();
    currentIndex = 0;
}

size_t CommandHistory::size() const {
    return history.size();
}
