#include "Workflow.h"
#include "Keyboard.h"

int main()
{
    Keyboard keyboard;

    // Регистрируем клавиши и связываем их с действиями
    keyboard.registerKey("A", []() { std::cout << "Key A pressed\n"; }, []() { std::cout << "Key A action undone\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C pressed\n"; }, []() { std::cout << "Ctrl+C action undone\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V pressed\n"; }, []() { std::cout << "Ctrl+V action undone\n"; });

    Workflow workflow(keyboard);

    // Добавляем в рабочий процесс действия: нажатие клавиш и отмену последних двух действий
    workflow.addAction([&]() { workflow.keypress("A"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+C"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+V"); });
    workflow.addAction([&]() { workflow.undo(); });
    workflow.addAction([&]() { workflow.undo(); });

    // Запускаем рабочий процесс
    std::cout << "Beginning of work...\n";
    workflow.perform();

    // Меняем действия, связанные с нажатием клавиш и повторно запускаем рабочий процесс
    std::cout << "\nReassigning keys and restarting the process...\n";
    keyboard.registerKey("A", []() { std::cout << "Key A now displays this message\n"; }, []() { std::cout << "Undo action for A\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C now it doesn't do anything\n"; }, []() { std::cout << "Undo action for Ctrl+C\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V now says hi\n"; }, []() { std::cout << "Undo action for Ctrl+V\n"; });

    workflow.perform();

    // Проверяем, зарегистрирована ли клавиша "Ctrl+V"
    if (keyboard.isKeyRegistered("Ctrl+V"))
    {
        std::cout << "The Ctrl+V key is registered in the system\n";
    }

    return 0;
}
