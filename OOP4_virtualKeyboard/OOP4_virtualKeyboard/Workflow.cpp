#include "Workflow.h"

void Workflow::keypress(const std::string& key)
{
    keyboard.pressKey(key);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // задержка, имитирующая нажатие клавиш
}

void Workflow::undo()
{
    keyboard.undo();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Выполняем все действия в workflow
void Workflow::perform() 
{
    for (const auto& action : actions)
    {
        action();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Добавляем действие в workflow
void Workflow::addAction(const Action& action)
{
    actions.push_back(action);
}
