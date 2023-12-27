//
// Created by Yan on 10.11.2023.
//

#ifndef USER_DATABASE_IREPOSITORY_H
#define USER_DATABASE_IREPOSITORY_H

#include <vector>

namespace entity {
    template<class T>
    class IRepository {
        virtual std::vector<T> getAll() = 0;

        virtual void add(T item) = 0;

        virtual void remove(T item) = 0;

        virtual void update(T item) = 0;
    };
}

#endif //USER_DATABASE_IREPOSITORY_H
