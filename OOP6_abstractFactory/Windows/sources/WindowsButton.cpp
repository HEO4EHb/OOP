//
// Created by Yan on 15/12/2023.
//

#include "../headers/WindowsButton.h"

#include <iostream>

using namespace factories;

void WindowsButton::setPosition() {
    std::cout << "The setPosition method was called on the WindowsButton control" << std::endl;
}

void WindowsButton::getPosition() {
    std::cout << "The getPosition method was called on the WindowsButton control" << std::endl;
}

void WindowsButton::setText() {
    std::cout << "The setText method was called on the WindowsButton control" << std::endl;
}

void WindowsButton::getText() {
    std::cout << "The getText method was called on the WindowsButton control" << std::endl;
}

void WindowsButton::click() {
    std::cout << "The click method of the WindowsButton control has been called" << std::endl;
}