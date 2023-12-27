//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_LINUXFORM_H
#define ABSTRACT_FACTORY_LINUXFORM_H

#include "../../Controls/Form.h"

namespace factories {
    class LinuxForm : public Form {
        void setPosition() override;

        void getPosition() override;

        void addControl() override;
    };
}

#endif //ABSTRACT_FACTORY_LINUXFORM_H
