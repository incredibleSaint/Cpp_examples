#include <iostream>
//#include "DummyMethod.h"
#include "SmartMethod.h"
/**
 * @brief This project allow to have partition template overload
 */
int main() {

    A <int, double> a;
    A <float, double> b;

    a.func(); // for int
    b.func(); // for all
    return 0;
}
