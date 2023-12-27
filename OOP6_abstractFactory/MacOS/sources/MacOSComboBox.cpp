//
// Created by Yan on 15/12/2023.
//

#include "../headers/MacOSComboBox.h"

#include <iostream>

using namespace factories;

void MacOSComboBox::setPosition() {
    std::cout << "Вызван метод setPosition у контролла MacOSComboBox" << std::endl;
}

void MacOSComboBox::getPosition() {
    std::cout << "Вызван метод getPosition у контролла MacOSComboBox" << std::endl;
}

void MacOSComboBox::getSelectedIndex() {
    std::cout << "Вызван метод getSelectedIndex у контролла MacOSComboBox" << std::endl;
}

void MacOSComboBox::setSelectedIndex() {
    std::cout << "Вызван метод setSelectedIndex у контролла MacOSComboBox" << std::endl;
}

void MacOSComboBox::setItems() {
    std::cout << "Вызван метод setItems( у контролла MacOSComboBox" << std::endl;
}

void MacOSComboBox::getItems() {
    std::cout << "Вызван метод getItems у контролла MacOSComboBox" << std::endl;
}
