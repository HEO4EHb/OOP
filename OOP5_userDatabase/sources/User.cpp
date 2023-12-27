// Created by Yan on 10.11.2023.

#include "../headers/User.h"

#include <string>
#include <utility>

using namespace entity;

// Реализация конструктора класса User
User::User(const int &id,
           std::string name,
           std::string login,
           std::string password)
        : m_id{id},
          m_name{std::move(name)},
          m_login{std::move(login)},
          m_password{std::move(password)} {}

// Метод для получения идентификатора пользователя
int User::getId() const {
    return m_id;
}

// Метод для получения логина пользователя
std::string User::getLogin() const {
    return m_login;
}

// Метод для установки логина пользователя
[[maybe_unused]] void User::setLogin(const std::string &login) {
    m_login = login;
}

// Метод для получения пароля пользователя
std::string User::getPassword() const {
    return m_password;
}

// Метод для установки пароля пользователя
[[maybe_unused]] void User::setPassword(const std::string &password) {
    m_password = password;
}

// Метод для получения имени пользователя
std::string User::getName() const {
    return m_name;
}

// Метод для установки имени пользователя
[[maybe_unused]] void User::setName(const std::string &name) {
    m_name = name;
}
