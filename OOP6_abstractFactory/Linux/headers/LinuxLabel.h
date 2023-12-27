//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_LINUXLABEL_H
#define ABSTRACT_FACTORY_LINUXLABEL_H

#include "../../Controls/Label.h"

namespace factories {
    class LinuxLabel : public Label {
        void setPosition() override;

        void getPosition() override;

        void setText() override;

        void getText() override;
    };
}

#endif //ABSTRACT_FACTORY_LINUXLABEL_H
