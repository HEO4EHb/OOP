//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_MACOSFORM_H
#define ABSTRACT_FACTORY_MACOSFORM_H

#include "../../Controls/Form.h"

namespace factories {
    class MacOSForm : public Form {
        void setPosition() override;

        void getPosition() override;

        void addControl() override;
    };
}

#endif //ABSTRACT_FACTORY_MACOSFORM_H
