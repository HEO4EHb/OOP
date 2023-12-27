//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_COMBOBOX_H
#define ABSTRACT_FACTORY_COMBOBOX_H

#include "Control.h"

namespace factories {
    class ComboBox : public Control {
    public:
        virtual void getSelectedIndex() = 0;

        virtual void setSelectedIndex() = 0;

        virtual void setItems() = 0;

        virtual void getItems() = 0;


        virtual ~ComboBox() = default;
    };
}

#endif //ABSTRACT_FACTORY_COMBOBOX_H
