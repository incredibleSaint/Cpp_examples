//
// Created by s on 06.01.2022.
//

#ifndef TYPE2TYPE_SMARTMETHOD_H
#define TYPE2TYPE_SMARTMETHOD_H
#include <iostream>

template <typename T> struct Type2Type {
//    typedef T OriginalType;
};


template <typename T, typename S> struct A {
    void func() {
        foo(Type2Type<T>{});
    };

private:
    template <typename V> void foo(V v) { std::cout << "all types, except int" << std::endl; };
    void foo(Type2Type<int>) { std::cout << "overload for int" << std::endl; };

};
#endif //TYPE2TYPE_SMARTMETHOD_H
