//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_LINUXCOMBOBOX_H
#define ABSTRACT_FACTORY_LINUXCOMBOBOX_H

#include "../../Controls/ComboBox.h"

namespace factories {
    class LinuxComboBox : public ComboBox {
        void setPosition() override;

        void getPosition() override;

        void getSelectedIndex() override;

        void setSelectedIndex() override;

        void setItems() override;

        void getItems() override;
    };
}

#endif //ABSTRACT_FACTORY_LINUXCOMBOBOX_H
