//
// Created by Yan on 10.11.2023.
//

#include "../headers/UserRepository.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>

using namespace entity;

// Конструктор класса UserRepository, принимающий путь к репозиторию
UserRepository::UserRepository(std::string reposPath) :
        m_reposPath{std::move(reposPath)} {}

// Метод для получения пути к репозиторию
std::string UserRepository::getReposPath() {
    return m_reposPath;
}

// Метод для получения всех пользователей из репозитория
std::vector<User> UserRepository::getAll() {
    std::vector<User> users;
    std::string user;

    // Открытие файла для чтения пользовательских данных
    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        // Чтение файла построчно
        while (std::getline(inputFile, user)) {
            // Поиск разделителей между данными пользователя в строке
            size_t idSeparator = user.find("; ");
            size_t nameSeparator = user.find("; ", idSeparator + 2);
            size_t loginSeparator = user.find("; ", nameSeparator + 2);

            // Проверка, что разделители найдены
            if (idSeparator == std::string::npos || nameSeparator == std::string::npos ||
                loginSeparator == std::string::npos) {
                continue;
            }

            // Извлечение данных пользователя из строки и добавление в вектор
            int userId = std::stoi(user.substr(0, idSeparator));
            std::string userName = user.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
            std::string userLogin = user.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);
            std::string userPassword = user.substr(loginSeparator + 2, user.length() - loginSeparator - 2);

            users.emplace_back(userId, userName, userLogin, userPassword);
        }
    }

    // Закрытие файла после чтения
    inputFile.close();

    return users;
}

// Метод для добавления пользователя в репозиторий
void UserRepository::add(User user) {
    // Открытие файла для записи пользовательских данных в конец файла
    std::ofstream outputFile;
    outputFile.open(m_reposPath, std::ios::app);
    if (outputFile.is_open()) {
        // Запись данных пользователя в файл
        outputFile << user.getId() << "; "
                   << user.getName() << "; "
                   << user.getLogin() << "; "
                   << user.getPassword()
                   << std::endl;
    }
    // Закрытие файла после записи
    outputFile.close();
}

// Метод для удаления пользователя из репозитория
void UserRepository::remove(User user) {
    // Создание вектора для хранения данных пользователя и текста файла
    std::vector<User> users;
    std::string userString;
    std::string fileText;

    // Открытие файла для чтения пользовательских данных
    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        // Чтение файла построчно
        while (std::getline(inputFile, userString)) {
            // Поиск разделителей между данными пользователя в строке
            size_t idSeparator = userString.find("; ");

            // Проверка, что разделители найдены
            if (idSeparator == std::string::npos) {
                continue;
            }

            // Извлечение идентификатора пользователя из строки
            int tempUserId = std::stoi(userString.substr(0, idSeparator));

            // Если идентификатор не совпадает с идентификатором пользователя, добавить в вектор
            if (tempUserId != user.getId()) {
                fileText.insert(fileText.size(), userString);
                fileText.insert(fileText.size(), "\n");
            }
        }
    }

    // Закрытие файла после чтения
    inputFile.close();

    // Открытие файла для записи весь текст без удаленного пользователя
    std::ofstream outputFile;
    outputFile.open(m_reposPath);
    if (outputFile.is_open()) {
        outputFile << fileText;
    }
    // Закрытие файла после записи
    outputFile.close();
}

// Метод для обновления данных пользователя в репозитории
void UserRepository::update(User user) {
    // Создание вектора для хранения данных пользователя и текста файла
    std::vector<User> users;
    std::string userString;
    std::string updatedUser = std::to_string(user.getId()) + "; "
                              + user.getName() + "; "
                              + user.getLogin() + "; "
                              + user.getPassword() + "\n";
    std::string fileText;

    // Открытие файла для чтения пользовательских данных
    std::ifstream inputFile(m_reposPath);

    if (inputFile.is_open()) {
        // Чтение файла построчно
        while (std::getline(inputFile, userString)) {
            // Поиск разделителей между данными пользователя в строке
            size_t idSeparator = userString.find("; ");

            // Проверка, что разделители найдены
            if (idSeparator == std::string::npos) {
                continue;
            }

            // Извлечение идентификатора пользователя из строки
            int tempUserId = std::stoi(userString.substr(0, idSeparator));

            // Если идентификатор не совпадает с идентификатором пользователя, добавить в вектор
            if (tempUserId != user.getId()) {
                fileText.insert(fileText.size(), userString);
                fileText.insert(fileText.size(), "\n");
            } else {
                // Если идентификатор совпадает, добавить обновленные данные пользователя
                fileText.insert(fileText.size(), updatedUser);
            }
        }
    }

    // Закрытие файла после чтения
    inputFile.close();

    // Открытие файла для записи весь текст с обновленными данными пользователя
    std::ofstream outputFile;
    outputFile.open(m_reposPath);
    if (outputFile.is_open()) {
        outputFile << fileText;
    }
    // Закрытие файла после записи
    outputFile.close();
}

// Метод для получения пользователя по идентификатору
User UserRepository::getById(int id) {
    // Создание объекта User с пустыми данными
    User user = User(0, "", "", "");
    std::string userString;

    // Открытие файла для чтения пользовательских данных
    std::ifstream inputFile(m_reposPath);

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

            // Извлечение идентификатора пользователя из строки
            int userId = std::stoi(userString.substr(0, idSeparator));

            // Если идентификатор совпадает с запрошенным, создать объект User с данными
            if (userId == id) {
                std::string userName = userString.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
                std::string userLogin = userString.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);
                std::string userPassword = userString.substr(loginSeparator + 2, userString.length() - loginSeparator - 2);

                user = User(userId, userName, userLogin, userPassword);
            }
        }
    }

    // Закрытие файла после чтения
    inputFile.close();

    return user;
}

// Метод для получения пользователя по логину
User UserRepository::getByLogin(std::string login) {
    // Создание объекта User с пустыми данными
    User user = User(0, "", "", "");
    std::string userString;

    // Открытие файла для чтения пользовательских данных
    std::ifstream inputFile(m_reposPath);

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

            // Извлечение логина пользователя из строки
            std::string userLogin = userString.substr(nameSeparator + 2, loginSeparator - nameSeparator - 2);

            // Если логин совпадает с запрошенным, создать объект User с данными
            if (userLogin == login) {
                int userId = std::stoi(userString.substr(0, idSeparator));
                std::string userName = userString.substr(idSeparator + 2, nameSeparator - idSeparator - 2);
                std::string userPassword = userString.substr(loginSeparator + 2, userString.length() - loginSeparator - 2);

                user = User(userId, userName, userLogin, userPassword);
            }
        }
    }

    // Закрытие файла после чтения
    inputFile.close();

    return user;
}

