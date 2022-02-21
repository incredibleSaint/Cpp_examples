//
// Created by s on 01.01.2022.
//

#ifndef FUNCTIONTEMPLATES_DEFIN_IN_HEADER_H
#define FUNCTIONTEMPLATES_DEFIN_IN_HEADER_H




/*
 * @brief x   - number
 *        acc - output. start val = 1u
 *        n   - power
 */
template<typename T> T do_nth_power(T x, T acc, unsigned n) {
    while (n > 0) {
       if (n % 2 == 0x1) {
           acc *= x;
           n--;
       }
       else {
           x *= x;
           n /= 2;
       }
    }
    return acc;
}
#endif //FUNCTIONTEMPLATES_DEFIN_IN_HEADER_H
