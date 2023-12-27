//
// Created by Yan on 15/12/2023.
//

#include "../headers/MacOSFactory.h"
#include "../headers/MacOSButton.h"
#include "../headers/MacOSComboBox.h"
#include "../headers/MacOSForm.h"
#include "../headers/MacOSLabel.h"
#include "../headers/MacOSTextBox.h"

using namespace factories;

Form *MacOSFactory::createForm() {
    return new MacOSForm;
}

Label *MacOSFactory::createLabel() {
    return new MacOSLabel;
}

TextBox *MacOSFactory::createTextBox() {
    return new MacOSTextBox;
}

ComboBox *MacOSFactory::createComboBox() {
    return new MacOSComboBox;
}

Button *MacOSFactory::createButton() {
    return new MacOSButton;
}
