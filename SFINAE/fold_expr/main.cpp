#include <iostream>
#include <string>

//template <typename T>
class AddSpace {
    const int& ref;
public:
    AddSpace(const int &r) : ref(r) {}
    void dump(std::ostream &os) const {
        os << ref << ' ';
    }
};
//template <typename T>
std::ostream& operator<<(std::ostream &os, const AddSpace &el) {
    el.dump(os);// el.ref << ' ';
    return os;
}

template <typename ... T>
void print_all(T ... args) {
    (std::cout << ... << AddSpace(args)) << "\n";
}

template <typename ... T>
auto sum_all(T ... args) {
    return  (args  + ...) ;
}

int main() {
    print_all(4, 6, 3, 1);
    std::cout << "Sum = " << sum_all(83, -1, 93, 8);
    return 0;
}
