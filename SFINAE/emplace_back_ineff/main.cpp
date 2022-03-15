/*
 * Emplace vs push_back: push part.
 */

#include <iostream>
#include <cstring>

class Heavy {
    int n;
    int *t;
public:
    Heavy(int size) : n(size), t(new int[n]) {
        std::cout << "Heavy ctor" << std::endl;
    }

    Heavy(Heavy &&rhs) noexcept : Heavy(rhs) {
        std::cout << "Heavy move ctor" << std::endl;
    }

    Heavy(const Heavy &rhs) : n(rhs.n), t(new int[n]) {
        memcpy(t, rhs.t, n);
        std::cout << "Heavy copy ctor" << std::endl;
    }

    Heavy &operator=(Heavy &&rhs) = delete;
    Heavy &operator=(const Heavy &rhs) = delete;

    ~Heavy() {
        std::cout << "Heavy dtor" << std::endl;
        delete [] t;
    }
};




template <typename T> class Stack {

//    template <typename T>
    struct StackElem {
        T elem;
        StackElem *next;

        StackElem(T e, StackElem *n) : elem(e), next(n) { std::cout << "StackElem ctor" << std::endl; }
        template <typename ... Args>
        StackElem(Args &&... args, StackElem *n) : T(std::forward<Args>(args) ...), next(n) {}

        ~StackElem() { std::cout << "StackElem dtor" << std::endl; }
    };

    struct StackElem *top_ = nullptr;

public:
    template <typename ... Args>
    void emplace_back(Args &&... args);

    ~Stack();

};

template <typename T>
template <typename ... Args>
void Stack<T>::emplace_back(Args &&... args) {
    top_ = new StackElem(std::forward<Args>(args)..., top_);

}

template <typename T>
Stack<T>::~Stack() {
    struct StackElem *curr_top = top_;
    while (top_ != nullptr) {
        struct StackElem *tmp = curr_top->next;
        delete curr_top;
        top_ = tmp;
    }
}

int main() {
    Heavy h(100);
    Heavy h2(h);
    Heavy h3((Heavy(4)));

    Stack<Heavy> s;
    for (int i = 0; i < 3; i++) {
        s.emplace_back(i);
    }
    return 0;
}
