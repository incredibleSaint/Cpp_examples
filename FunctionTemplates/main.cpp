#include <iostream>
#include "module1.h"
#include "module2.h"

int main() {
    std::cout << do_nth_power_int(2, 8) << std::endl;
    std::cout << do_nth_power_uint32t(2, 5) << std::endl;

    std::cout << 1u << std::endl;
    return 0;
}
