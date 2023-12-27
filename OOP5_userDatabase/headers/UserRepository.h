//
// Created by Yan on 10.11.2023.
//

#ifndef USER_DATABASE_USERREPOSITORY_H
#define USER_DATABASE_USERREPOSITORY_H

#include "IRepository.h"
#include "IUserRepository.h"
#include "User.h"

#include <string>
#include <vector>

namespace entity {
    class UserRepository : public IUserRepository {
    public:
        explicit UserRepository(std::string reposPath);

        [[nodiscard]] std::string getReposPath();

        std::vector<User> getAll() override;

        void add(User user) override;

        void remove(User user) override;

        void update(User user) override;

        User getById(int id) override;

        User getByLogin(std::string login) override;

    private:
        std::string m_reposPath;
    };
}

#endif //USER_DATABASE_USERREPOSITORY_H
