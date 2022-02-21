#include <iostream>
#include "TemplTemplParams.h"
#include "UsingClasses.h"

/**
 * Here we can use
 * Stack<S, int>, not uncomfortable Stack<S<int>, int>.
 */
int main() {
    S<int> s;
    UserStack<S, int> stack;

    HDD<Deque, Vector, int> disk;

    disk.Print();
    Vector<int> v1{};
    v1.data = new int[22];
    v1.size = 22;
    disk.stack.AddNewContainer(&v1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
