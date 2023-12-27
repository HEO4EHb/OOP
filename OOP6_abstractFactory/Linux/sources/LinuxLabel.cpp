//
// Created by Yan on 15/12/2023.
//

#include "../headers/LinuxLabel.h"

#include <iostream>

using namespace factories;

void LinuxLabel::setPosition() {
    std::cout << "Вызван метод setPosition у контролла LinuxLabel" << std::endl;
}

void LinuxLabel::getPosition() {
    std::cout << "Вызван метод getPosition у контролла LinuxLabel" << std::endl;
}

void LinuxLabel::setText() {
    std::cout << "Вызван метод setText у контролла LinuxLabel" << std::endl;
}

void LinuxLabel::getText() {
    std::cout << "Вызван метод getText у контролла LinuxLabel" << std::endl;
}
