#pragma once

#include <iostream>
#include <functional>
#include <deque>
#include <thread>
#include <chrono>
#include <map>
#include <cassert>
#include <vector>
#include <windows.h>

// Создаем псевдоним для типов данных.
// Action - это функция, не принимающая аргументов и не возвращающая результатов.
// Keymap - это ассоциативный массив (карта), где каждая строка (имя клавиши) связана с парой действий: нажатие и отмена.

using Action = std::function<void()>;
using Keymap = std::map<std::string, std::pair<Action, Action>>;

class Keyboard
{
public:
    // Регистрируем клавишу и связываем ее с двумя действиями: основное и обратное (для undo)
    void registerKey(const std::string& key, const Action& action, const Action& undoAction = []() {})
    {
        keymap[key] = { action, undoAction };
    }
    // Производим нажатие клавиши. Если клавиша не зарегистрирована, сгенерируем исключение. Добавляем имя клавиши в историю и выполняем действие.
    void pressKey(const std::string& key);

    // Отменяем последнее действие, если история не пуста
    void undo();

    // Проверяем, зарегистрирована ли клавиша
    bool isKeyRegistered(const std::string& key) const;

private:
    Keymap keymap;
    std::deque<std::string> history; // история нажатий для отката
};

