//
// Created by s on 01.01.2022.
//
#include <cstdint>
#include "module1.h"
#include "defin_in_header.h"

int do_nth_power_int(int a, uint32_t n) {
    if (a < 2 || n < 1) return a;
    else return do_nth_power<int>(a, 1u, n);
}