//
// Created by Yan on 15/12/2023.
//

#include "../headers/WindowsFactory.h"
#include "../headers/WindowsButton.h"
#include "../headers/WindowsComboBox.h"
#include "../headers/WindowsForm.h"
#include "../headers/WindowsLabel.h"
#include "../headers/WindowsTextBox.h"

using namespace factories;

Form *WindowsFactory::createForm() {
    return new WindowsForm;
}

Label *WindowsFactory::createLabel() {
    return new WindowsLabel;
}

TextBox *WindowsFactory::createTextBox() {
    return new WindowsTextBox;
}

ComboBox *WindowsFactory::createComboBox() {
    return new WindowsComboBox;
}

Button *WindowsFactory::createButton() {
    return new WindowsButton;
}
