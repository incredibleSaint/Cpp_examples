//
// Created by s on 01.01.2022.
//

// module is one cpp and all includes .h

#include <cstdint>
#include "module2.h"
#include "defin_in_header.h"

uint32_t do_nth_power_uint32t(uint32_t a, uint32_t n) {
    if (a < 2 || n < 1) return a;
    else return do_nth_power<uint32_t>(a, 1u, n);
}

