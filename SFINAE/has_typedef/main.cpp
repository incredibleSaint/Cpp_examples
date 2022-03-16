#include <iostream>
#include <type_traits>

template <typename, typename = void>
struct has_foobar : std::false_type {};

template <typename T>
struct has_foobar<T, std::void_t<typename T::foobar>> : std::true_type {};

struct Foo { typedef int foobar; };
struct Bar {};

int main() {
    std::cout << has_foobar<Foo>{} << std::endl;

    std::cout << has_foobar<Bar>{} << std::endl;
}
