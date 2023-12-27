#pragma once

#include "Keyboard.h"

class Workflow
{
public:
    explicit Workflow(Keyboard& keyboard) : keyboard(keyboard) {}

    // Открываем доступ к методам нажатия клавиши и отмены в контексте рабочего процесса (workflow)
    void keypress(const std::string& key);

    void undo();

    // Выполняем все действия в рабочем процессе (workflow)
    void perform();

    // Добавляем действие в рабочий процесс (workflow)
    void addAction(const Action& action);

private:
    Keyboard& keyboard;
    std::vector<Action> actions; // вектор действий для выполнения в рабочем процессе (workflow)
};
