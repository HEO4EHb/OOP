//
// Created by Yan on 15/12/2023.
//

#ifndef ABSTRACT_FACTORY_CONTROL_H
#define ABSTRACT_FACTORY_CONTROL_H

namespace factories {
    class Control {
    public:
        virtual void setPosition() = 0;

        virtual void getPosition() = 0;
    };
}
#endif //ABSTRACT_FACTORY_CONTROL_H
