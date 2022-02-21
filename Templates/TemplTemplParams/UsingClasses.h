//
// Created by s on 08.01.2022.
//

#ifndef TEMPLTEMPLPARAMS_USINGCLASSES_H
#define TEMPLTEMPLPARAMS_USINGCLASSES_H
#include <iostream>

#include "TemplTemplParams.h"


template <typename T> struct Vector {
    T *data;
    int size;
};

template <template<typename Type> class Container,
          typename T
          > struct Deque {
    Container<T> *data[20];
    int curr_size = 0;
public:
              void AddNewContainer(Container<T> *c) {
                 if (curr_size < 20) {
                     data[curr_size++] = c;
                 }
              }
};


template <
        template <template <typename > typename, typename > typename Stack,
        template <typename > typename Container,
        typename ElemType
>
class HDD : public StackMachine<Stack, Container, ElemType>  {
public:
    void Print() {
        std::cout << "It is HDD" << std::endl;
    }
};
#endif //TEMPLTEMPLPARAMS_USINGCLASSES_H
