//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_WINDOWSBUTTON_H
#define ABSTRACT_FACTORY_WINDOWSBUTTON_H

#include "../../Controls/Button.h"

namespace factories {
    class WindowsButton : public Button {
        void setPosition() override;

        void getPosition() override;

        void setText() override;

        void getText() override;

        void click() override;
    };
}

#endif //ABSTRACT_FACTORY_WINDOWSBUTTON_H
