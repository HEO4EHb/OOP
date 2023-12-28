cmake_minimum_required(VERSION 3.23)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab5
        IRepository.h
        IUserManager.h
        IUserRepository.h
        main.cpp
        User.cpp
        User.h
        UserManager.cpp
        UserManager.h
        UserRepository.h
        UserRepository_impl.h)
