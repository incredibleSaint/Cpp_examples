//
// Created by s on 02.01.2022.
//

#include <cstdint>
#include "tmp_max.h"

int max_user2(int x, int y) {
    return tmplt_max<int>(x + 1, y);
}
