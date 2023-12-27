#include "Keyboard.h"

// Производим нажатие клавиши. Если клавиша не зарегистрирована, сгенерируем исключение. Добавляем имя клавиши в историю и выполняем действие.
void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "Unknown key pressed");
    history.push_back(key);
    keymap[key].first();
}

// Отменяем последнее действие, если история не пуста
void Keyboard::undo() 
{
    if (!history.empty())
    {
        std::cout << "Undo action for key: " << history.back() << "\n";
        keymap[history.back()].second();
        history.pop_back();
    }
}

// Проверяем, зарегистрирована ли клавиша
bool Keyboard::isKeyRegistered(const std::string& key) const
{
    return keymap.count(key) > 0;
}