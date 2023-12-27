//
// Created by Yan on 10.11.2023.
//

#ifndef USER_DATABASE_USERMANAGER_H
#define USER_DATABASE_USERMANAGER_H

#include "IUserManager.h"
#include "User.h"
#include "UserRepository.h"

namespace entity {
    class UserManager : IUserManager {
    public:
        explicit UserManager(UserRepository &repos);

        void signIn(User user) override;

        void signOut(User user) override;

        bool isAuthorized() override;

    private:
        UserRepository &m_repos;

        User *m_user;
    };
}


#endif //USER_DATABASE_USERMANAGER_H
