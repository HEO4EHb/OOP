//
// Created by Yan on 15/12/2023.
//

#include "../headers/LinuxTextBox.h"

#include <iostream>

using namespace factories;

void LinuxTextBox::setPosition() {
    std::cout << "Вызван метод setPosition у контролла LinuxTextBox" << std::endl;
}

void LinuxTextBox::getPosition() {
    std::cout << "Вызван метод getPosition у контролла LinuxTextBox" << std::endl;
}

void LinuxTextBox::setText() {
    std::cout << "Вызван метод setText у контролла LinuxTextBox" << std::endl;
}

void LinuxTextBox::getText() {
    std::cout << "Вызван метод getText у контролла LinuxTextBox" << std::endl;
}

void LinuxTextBox::onValueChanged() {
    std::cout << "Вызван метод onValueChanged у контролла LinuxTextBox" << std::endl;
}
