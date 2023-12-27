//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_OS_H
#define ABSTRACT_FACTORY_OS_H

#include "../Controls/Form.h"
#include "../Controls/Label.h"
#include "../Controls/TextBox.h"
#include "../Controls/ComboBox.h"
#include "../Controls/Button.h"

#include <vector>

namespace factories {
    class OS {
    public:
        ~OS();

        std::vector<Form *> vf;
        std::vector<Label *> vl;
        std::vector<TextBox *> vtb;
        std::vector<ComboBox *> vcb;
        std::vector<Button *> vb;
    };
}


#endif //ABSTRACT_FACTORY_OS_H
