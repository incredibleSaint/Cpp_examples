#include <iostream>

/*
 * Отображение из целых чисел на типы называется интегральной константой.
 */
template <typename T, T v> struct integral_constant {
    integral_constant() { std::cout << "integral const ctor" << std::endl;}
    static const T value = v;
    using value_type = T;
    using type = integral_constant;
    operator value_type() const { return value; }
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template <typename T, typename U> struct is_same : false_type {
    is_same() { std::cout << "is_same false ctor\n"; }
};
template <typename T> struct is_same<T, T> : true_type {
    is_same() { std::cout << "is_same true ctor\n"; }
};

template <typename T, typename U>
using is_same_t = typename is_same<T, U>::type;

int main() {
    using ic6 = integral_constant<int, 6>;
    ic6 obj;
    auto n = 7 * obj; // implicit cast via operator value_type()
//    auto n = 7 * integral_constant<int, 6>::value_type(obj);
    std::cout << n << std::endl;

    // true_type, false_type
    auto the_same = is_same<int, int>{};
    std::cout << the_same << std::endl;

    auto not_the_same = is_same_t<int, double>{};
    std::cout << not_the_same << std::endl;

//    the_same = is_same<int, double>{};
    return 0;
}
