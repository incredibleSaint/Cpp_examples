#include <iostream>
#include "templates.h"

template <typename T>
template <typename R>
R DataReader<T>::read() {
    R res = source_.template read<double>();
    return res;
}

int main() {
    Data d ;
    DataReader<Data> dr(d);
    int res = dr.read<int>();
    std::cout << "return val = " <<
                 res << std::endl;
    return 0;
}
