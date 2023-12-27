//
//Created by Yan on 10.11.2023.
//

#ifndef USER_DATABASE_IUSERREPOSITORY_H
#define USER_DATABASE_IUSERREPOSITORY_H

#include "IRepository.h"
#include "User.h"

#include <string>

namespace entity {
    class IUserRepository : IRepository<User> {
        virtual User getById(int id) = 0;

        virtual User getByLogin(std::string login) = 0;
    };
}

#endif //USER_DATABASE_IUSERREPOSITORY_H
