//
// Created by Yan on 15/12/2023.
//

#include "../headers/MacOSLabel.h"

#include <iostream>

using namespace factories;

void MacOSLabel::setPosition() {
    std::cout << "Вызван метод setPosition у контролла MacOSLabel" << std::endl;
}

void MacOSLabel::getPosition() {
    std::cout << "Вызван метод getPosition у контролла MacOSLabel" << std::endl;
}

void MacOSLabel::setText() {
    std::cout << "Вызван метод setText у контролла MacOSLabel" << std::endl;
}

void MacOSLabel::getText() {
    std::cout << "Вызван метод getText у контролла MacOSLabel" << std::endl;
}
