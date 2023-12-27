//
// Created by Yan on 15/12/2023.
//

#include "../headers/LinuxButton.h"

#include <iostream>

using namespace factories;

void LinuxButton::setPosition() {
    std::cout << "Вызван метод setPosition у контролла LinuxButton" << std::endl;
}

void LinuxButton::getPosition() {
    std::cout << "Вызван метод getPosition у контролла LinuxButton" << std::endl;
}

void LinuxButton::setText() {
    std::cout << "Вызван метод setText у контролла LinuxButton" << std::endl;
}

void LinuxButton::getText() {
    std::cout << "Вызван метод getText у контролла LinuxButton" << std::endl;
}

void LinuxButton::click() {
    std::cout << "Вызван метод click у контролла LinuxButton" << std::endl;
}
