//
// Created by s on 06.01.2022.
//

#ifndef TYPE2TYPE_DUMMYMETHOD_H
#define TYPE2TYPE_DUMMYMETHOD_H
#include <iostream>

/**
 * It isn't right, because it can be really expensive constructor of: T dummy;
 * Or expensive copy constructor: foo(dummy);
 *
 * It can be solved by pointers, but as usual:
 * - possibility of nullptr,
 * - pointer also has size (4 bytes)
 *
 */

template <typename T, typename S> struct A {
    void func() {
        T dummy;
        foo(dummy);
    };

private:
    template <typename V> void foo(V v) { std::cout << "all types, except int" << std::endl; };
    void foo(int) { std::cout << "overload for int" << std::endl; };

};

#endif //TYPE2TYPE_DUMMYMETHOD_H
