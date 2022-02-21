//
// Created by s on 05.01.2022.
//

#ifndef USINGWORDTHIS_THIS_H
#define USINGWORDTHIS_THIS_H

template <typename T> struct Base {
    void foo () { std::cout << "Base::foo();" << std::endl; };

};

template <typename T> struct Derived: Base<T> {
        void bar() { this->foo(); };
};
#endif //USINGWORDTHIS_THIS_H
