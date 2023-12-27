//
// Created by Yan on 10.11.2023.
//

#ifndef USER_DATABASE_USER_H
#define USER_DATABASE_USER_H

#include <string>

namespace entity {
    class User {
    public:
        User(const int &id,
             std::string name,
             std::string login,
             std::string password);

        [[nodiscard]] int getId() const;

        [[nodiscard]] std::string getLogin() const;

        [[maybe_unused]] void setLogin(const std::string &login);

        [[nodiscard]] std::string getPassword() const;

        [[maybe_unused]] void setPassword(const std::string &password);

        [[nodiscard]] std::string getName() const;

        [[maybe_unused]] void setName(const std::string &name);

    private:
        int m_id;
        std::string m_login;
        std::string m_password;
        std::string m_name;
    };
}

#endif //USER_DATABASE_USER_H
