//
// Created by s on 02.01.2022.
//

#ifndef INSTANCETEMPLMANAGEMENT_TMP_MAX_H
#define INSTANCETEMPLMANAGEMENT_TMP_MAX_H

template<typename T>
T tmplt_max(T a, T b) {
    return a > b ? a : b;
}

// block instance of <int> everywhere
extern template int tmplt_max<int>(int a, int b);

int max_user1(int a, int b);
int max_user2(int a, int b);

#endif //INSTANCETEMPLMANAGEMENT_TMP_MAX_H

