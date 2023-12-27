//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_WINDOWSCOMBOBOX_H
#define ABSTRACT_FACTORY_WINDOWSCOMBOBOX_H

#include "../../Controls/ComboBox.h"

namespace factories {
    class WindowsComboBox : public ComboBox {
        void setPosition() override;

        void getPosition() override;

        void getSelectedIndex() override;

        void setSelectedIndex() override;

        void setItems() override;

        void getItems() override;
    };
}

#endif //ABSTRACT_FACTORY_WINDOWSCOMBOBOX_H
