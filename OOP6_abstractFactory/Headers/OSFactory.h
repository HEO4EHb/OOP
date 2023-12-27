//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_OSFACTORY_H
#define ABSTRACT_FACTORY_OSFACTORY_H

#include "../Controls/Form.h"
#include "../Controls/Label.h"
#include "../Controls/TextBox.h"
#include "../Controls/ComboBox.h"
#include "../Controls/Button.h"

namespace factories {
    class OSFactory {
    public:
        virtual Form *createForm() = 0;

        virtual Label *createLabel() = 0;

        virtual TextBox *createTextBox() = 0;

        virtual ComboBox *createComboBox() = 0;

        virtual Button *createButton() = 0;

        virtual ~OSFactory() = default;
    };
}

#endif //ABSTRACT_FACTORY_OSFACTORY_H
