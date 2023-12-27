//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_FORM_H
#define ABSTRACT_FACTORY_FORM_H

#include "Control.h"

namespace factories {
    class Form : public Control {
    public:
        virtual void addControl() = 0;

        virtual ~Form() = default;
    };
}


#endif //ABSTRACT_FACTORY_FORM_H
