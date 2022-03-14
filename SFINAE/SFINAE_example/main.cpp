#include <iostream>
//! substitution failure is not an error
template <typename T> T max(T a, T b) { return a < b ? b : a; };
template <typename T, typename U> auto max(T a, U b) { return a < b ? b : a; }


int negate(int n) { return -n; }
template <typename T> T negate(const T& t) {
    typename T::value_type n = -t();
    return n;
}

int main() {
    int g = max(1, 1.0); // substitution to 1 is failed
                               // substitution to 2 is successful.

    auto n = negate(2.0); // negate(const T& t) win overload, but second phase error => compilation error.
    return 0;
}
