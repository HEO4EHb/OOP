//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_LINUXFACTORY_H
#define ABSTRACT_FACTORY_LINUXFACTORY_H

#include "../../Headers/OSFactory.h"
#include "../../Controls/Form.h"
#include "../../Controls/Label.h"
#include "../../Controls/TextBox.h"
#include "../../Controls/ComboBox.h"
#include "../../Controls/Button.h"

namespace factories {
    class LinuxFactory : public OSFactory {
        Form *createForm() override;

        Label *createLabel() override;

        TextBox *createTextBox() override;

        ComboBox *createComboBox() override;

        Button *createButton() override;
    };
}


#endif //ABSTRACT_FACTORY_LINUXFACTORY_H
