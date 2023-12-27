//
// Created by Yan on 15/12/2023.
//

#include "../Headers/OS.h"

using namespace factories;

factories::OS::~OS() {
    int i;
    for (i = 0; i < vf.size(); ++i) delete vf[i];
    for (i = 0; i < vl.size(); ++i) delete vl[i];
    for (i = 0; i < vtb.size(); ++i) delete vtb[i];
    for (i = 0; i < vcb.size(); ++i) delete vcb[i];
    for (i = 0; i < vb.size(); ++i) delete vb[i];
}
