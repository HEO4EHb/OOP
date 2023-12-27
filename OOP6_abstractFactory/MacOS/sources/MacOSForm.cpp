//
// Created by Honor on 04.12.2023.
//

#include "../headers/MacOSForm.h"

#include <iostream>

using namespace factories;

void MacOSForm::setPosition() {
    std::cout << "Вызван метод setPosition у контролла MacOSForm" << std::endl;
}

void MacOSForm::getPosition() {
    std::cout << "Вызван метод getPosition у контролла MacOSForm" << std::endl;
}

void MacOSForm::addControl() {
    std::cout << "Вызван метод addControl у контролла MacOSForm" << std::endl;
}
