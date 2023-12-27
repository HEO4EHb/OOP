//
// Created by Yan on 15/12/2023.
//

#include "../headers/WindowsForm.h"

#include <iostream>

using namespace factories;

void WindowsForm::setPosition() {
    std::cout << "The setPosition method was called on the WindowsForm control" << std::endl;
}

void WindowsForm::getPosition() {
    std::cout << "The getPosition method was called on the WindowsForm control" << std::endl;
}

void WindowsForm::addControl() {
    std::cout << "The addControl method was called on the WindowsForm control" << std::endl;
}