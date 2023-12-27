// Created by Yan on 10.11.2023.

#include "../headers/UserManager.h"


#include <fstream>

using namespace entity;

// Конструктор класса UserManager, принимающий ссылку на объект UserRepository
UserManager::UserManager(UserRepository &repos) : m_repos{repos}, m_user{nullptr} {}

// Метод для входа пользователя в систему
void UserManager::signIn(User user) {
    // Проверка, что пользователь еще не вошел в систему
    if (m_user != nullptr) {
        return;
    }

    // Открытие файла для чтения пользовательских данных
    std::string userString;
    std::ifstream inputFile(m_repos.getReposPath());

    if (inputFile.is_open()) {
        // Чтение файла построчно
        while (std::getline(inputFile, userString)) {
            // Поиск разделителей между данными пользователя в строке
            size_t idSeparator = userString.find("; ");
            size_t nameSeparator = userString.find("; ", idSeparator + 2);
            size_t loginSeparator = userString.find("; ", nameSeparator + 2);

            // Проверка, что разделители найдены
            if (idSeparator == std::string::npos || nameSeparator == std::string::npos ||
                loginSeparator == std::string::npos) {
                continue;
            }

            // Извлечение данных пользователя из строки
            int userId = std::stoi(userString.substr(0, idSeparator));
            std::string userLogin = userString.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);
            std::string userName = userString.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
            std::string userPassword = userString.substr(loginSeparator + 2, userString.length() - loginSeparator - 2);

            // Сравнение данных пользователя с данными, переданными при входе
            if (userId != user.getId()
                || userName != user.getName()
                || userLogin != user.getLogin()
                || userPassword != user.getPassword()) {
                continue;
            }

            // Создание объекта User при успешной аутентификации
            m_user = new User(userId, userName, userLogin, userPassword);
        }
    }

    // Закрытие файла после чтения
    inputFile.close();
}

// Метод для выхода пользователя из системы
void UserManager::signOut(User user) {
    // Установка указателя пользователя в nullptr при выходе
    m_user = nullptr;
}

// Метод для проверки, аутентифицирован ли пользователь
bool UserManager::isAuthorized() {
    // Возвращает true, если указатель пользователя не установлен (nullptr)
    return m_user == nullptr;
}
