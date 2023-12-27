//
// Created by Yan on 15/12/2023.
//

#include "../headers/MacOSButton.h"

#include <iostream>

using namespace factories;

void MacOSButton::setPosition() {
    std::cout << "Вызван метод setPosition у контролла MacOSButton" << std::endl;
}

void MacOSButton::getPosition() {
    std::cout << "Вызван метод getPosition у контролла MacOSButton" << std::endl;
}

void MacOSButton::setText() {
    std::cout << "Вызван метод setText у контролла MacOSButton" << std::endl;
}

void MacOSButton::getText() {
    std::cout << "Вызван метод getText у контролла MacOSButton" << std::endl;
}

void MacOSButton::click() {
    std::cout << "Вызван метод click у контролла MacOSButton" << std::endl;
}
