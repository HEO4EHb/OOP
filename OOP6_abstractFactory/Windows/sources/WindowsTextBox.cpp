//
// Created by Yan on 12/15/2023.
//

#include "../headers/WindowsTextBox.h"

#include <iostream>

using namespace factories;

void WindowsTextBox::setPosition() {
    std::cout << "The setPosition method was called on the WindowsTextBox control" << std::endl;
}

void WindowsTextBox::getPosition() {
    std::cout << "The getPosition method was called on the WindowsTextBox control" << std::endl;
}

void WindowsTextBox::setText() {
    std::cout << "The setText method was called on the WindowsTextBox control" << std::endl;
}

void WindowsTextBox::getText() {
    std::cout << "The getText method was called on the WindowsTextBox control" << std::endl;
}

void WindowsTextBox::onValueChanged() {
    std::cout << "The onValueChanged method was called on the WindowsTextBox control" << std::endl;
}