//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_TEXTBOX_H
#define ABSTRACT_FACTORY_TEXTBOX_H

#include "Control.h"

namespace factories {
    class TextBox : public Control {
    public:
        virtual void setText() = 0;

        virtual void getText() = 0;

        virtual void onValueChanged() = 0;

        virtual ~TextBox() = default;
    };
}

#endif //ABSTRACT_FACTORY_TEXTBOX_H
