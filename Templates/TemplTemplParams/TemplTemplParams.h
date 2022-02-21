//
// Created by s on 08.01.2022.
//

#ifndef TEMPLTEMPLPARAMS_TEMPLTEMPLPARAMS_H
#define TEMPLTEMPLPARAMS_TEMPLTEMPLPARAMS_H

template <typename T> struct S {};




template <template <typename> class Storage,
          typename Element
          > struct UserStack {};

template <
            template <template <typename > typename, typename > typename Stack,
            template <typename > typename Container,
            typename ElemType
            > struct StackMachine  {
                Stack<Container, ElemType> stack;
            };

#endif //TEMPLTEMPLPARAMS_TEMPLTEMPLPARAMS_H
