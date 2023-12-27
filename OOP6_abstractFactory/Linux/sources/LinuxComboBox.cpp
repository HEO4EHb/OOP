//
// Created by Yan on 15/12/2023.
//

#include "../headers/LinuxComboBox.h"

#include <iostream>

using namespace factories;

void LinuxComboBox::setPosition() {
    std::cout << "Вызван метод setPosition у контролла LinuxComboBox" << std::endl;
}

void LinuxComboBox::getPosition() {
    std::cout << "Вызван метод getPosition у контролла LinuxComboBox" << std::endl;
}

void LinuxComboBox::getSelectedIndex() {
    std::cout << "Вызван метод getSelectedIndex у контролла LinuxComboBox" << std::endl;
}

void LinuxComboBox::setSelectedIndex() {
    std::cout << "Вызван метод setSelectedIndex у контролла LinuxComboBox" << std::endl;
}

void LinuxComboBox::setItems() {
    std::cout << "Вызван метод setItems у контролла LinuxComboBox" << std::endl;
}

void LinuxComboBox::getItems() {
    std::cout << "Вызван метод getItems у контролла LinuxComboBox" << std::endl;
}
