//
// Created by Yan on 10.11.2023.
//

#ifndef USER_DATABASE_IUSERMANAGER_H
#define USER_DATABASE_IUSERMANAGER_H

#include "User.h"

namespace entity {
    class IUserManager {
        virtual void signIn(User user) = 0;

        virtual void signOut(User user) = 0;

        virtual bool isAuthorized() = 0;
    };
}

#endif //USER_DATABASE_IUSERMANAGER_H
