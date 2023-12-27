//
// Created by Yan on 15/12/2023.
//

#include "../headers/LinuxFactory.h"
#include "../headers/LinuxButton.h"
#include "../headers/LinuxComboBox.h"
#include "../headers/LinuxForm.h"
#include "../headers/LinuxLabel.h"
#include "../headers/LinuxTextBox.h"

using namespace factories;

Form *LinuxFactory::createForm() {
    return new LinuxForm;
}

Label *LinuxFactory::createLabel() {
    return new LinuxLabel;
}

TextBox *LinuxFactory::createTextBox() {
    return new LinuxTextBox;
}

ComboBox *LinuxFactory::createComboBox() {
    return new LinuxComboBox;
}

Button *LinuxFactory::createButton() {
    return new LinuxButton;
}
