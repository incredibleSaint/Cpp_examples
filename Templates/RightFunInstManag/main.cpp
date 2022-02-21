#include <iostream>
#include <cassert>

/**
 * Right instance management:
 * instance of tmplt_max in max_user1.o and max_user2.0.
 * g++ module1.cpp -c
 * g++ module2.cpp -c
 * objdump -d module1.o > module1.dis
 * objdump -d module2.o > module2.dis
 *
 * vim module1.dis
 * vim module2.dis
 */
#include "tmp_max.h"

int main() {
    assert(max_user1(0, 0) == 1);
    assert(max_user2(1, 0) == 1);
    return 0;
}
