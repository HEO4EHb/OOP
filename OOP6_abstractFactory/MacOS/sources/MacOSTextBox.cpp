//
// Created by Yan on 15/12/2023.
//

#include "../headers/MacOSTextBox.h"

#include <iostream>

using namespace factories;

void MacOSTextBox::setPosition() {
    std::cout << "Вызван метод setPosition у контролла MacOSTextBox" << std::endl;
}

void MacOSTextBox::getPosition() {
    std::cout << "Вызван метод getPosition у контролла MacOSTextBox" << std::endl;
}

void MacOSTextBox::setText() {
    std::cout << "Вызван метод setText у контролла MacOSTextBox" << std::endl;
}

void MacOSTextBox::getText() {
    std::cout << "Вызван метод getText у контролла MacOSTextBox" << std::endl;
}

void MacOSTextBox::onValueChanged() {
    std::cout << "Вызван метод onValueChanged у контролла MacOSTextBox" << std::endl;
}
