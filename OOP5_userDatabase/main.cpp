#include "headers/UserRepository.h"
#include "headers/UserManager.h"

using namespace entity;

int main() {
    // Создание объекта UserRepository с указанием пути к репозиторию
    UserRepository userRepository("../data/repos.txt");

    // Получение всех пользователей из репозитория
    std::vector<User> users = userRepository.getAll();

    // Добавление нового пользователя в репозиторий
    userRepository.add(User(2, "Daniil", "Tevs", "qwerty"));

    // Удаление пользователя из репозитория по идентификатору
    userRepository.remove(User(3, "Yan", "Matveyev", "coolpass"));

    // Обновление данных пользователя в репозитории
    userRepository.update(User(1, "Neegrow", "Gangsta", "superpass"));

    // Получение пользователя из репозитория по идентификатору
    User user = userRepository.getById(1);

    // Получение пользователя из репозитория по логину
    User user2 = userRepository.getByLogin("Gangsta");

    // Создание объекта UserManager с использованием UserRepository
    UserManager userManager(userRepository);

    // Вход пользователя в систему
    userManager.signIn(User(1, "Neegrow", "Gangsta", "superpass"));

    // Вход еще одного пользователя в систему
    userManager.signIn(User(2, "Daniil", "Tevs", "qwerty"));

    // Выход первого пользователя из системы
    userManager.signOut(User(1, "Neegrow", "Gangsta", "superpass"));

    // Вход в систему пользователя, который был удален (идентификатор 2)
    userManager.signIn(User(2, "Daniil", "Tevs", "qwerty"));

    // Выход из системы пользователя (идентификатор 2)
    userManager.signOut(User(2, "Daniil", "Tevs", "qwerty"));

    // Вход в систему пользователя, который был удален и снова добавлен (идентификатор 1)
    userManager.signIn(User(1, "Neegrow", "Gangsta", "superpass"));

    return 0;
}

