#include <iostream>



class A {
public:
    A() {
        std::cout << "ctor" << std::endl;
    }

    /**
     * Copy constructor
     */
     A(A&) {
         std::cout << "copy ctor" << std::endl;
     }

     /**
      * Move constructor
      */
     A(A&&) noexcept {
         std::cout << "move ctor" << std::endl;
     }

     A& operator=(A other) {
         std::cout << "copy assign" << std::endl;
         return *this;
     }

     A& operator=(A&&) noexcept {
         std::cout << "move assign" << std::endl;
         return *this;
     }
};

template <typename Foo, typename Arg>
decltype(auto) transparent(Foo foo, Arg&& arg) {
    std::cout << "TemplateFun" << std::endl;
    return foo(std::forward<Arg>(arg));
}

A foo(A a) {
    std::cout << "foo called" << std::endl;
    return a;
}

int main() {
//    auto lambda = [] (auto arg) { return arg; };
    A local_a;
    A aa = foo(local_a);
//    A ret = transparent(&foo, local_a);
    std::cout << "=---=" << std::endl;
    A ret1 = transparent(&foo, foo(std::move(local_a)));
    return 0;
}
