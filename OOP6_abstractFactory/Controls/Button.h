//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_BUTTON_H
#define ABSTRACT_FACTORY_BUTTON_H

#include "Control.h"

namespace factories {
    class Button : public Control {
    public:
        virtual void setText() = 0;

        virtual void getText() = 0;

        virtual void click() = 0;

        virtual ~Button() = default;
    };
}

#endif //ABSTRACT_FACTORY_BUTTON_H
