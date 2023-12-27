//
// Created by Yan on 15/12/2023.
//

#include "../Headers/Production.h"

using namespace factories;

OS *Production::createOS(OSFactory *factory) {
    OS *p = new OS;
    p->vf.push_back(factory->createForm());
    p->vl.push_back(factory->createLabel());
    p->vtb.push_back(factory->createTextBox());
    p->vcb.push_back(factory->createComboBox());
    p->vb.push_back(factory->createButton());

    return p;
}
