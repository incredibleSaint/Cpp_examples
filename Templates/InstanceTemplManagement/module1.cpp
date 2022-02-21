//
// Created by s on 02.01.2022.
//

#include "tmp_max.h"

int max_user1(int x, int y) {
    return tmplt_max<int>(x, y + 1);
}