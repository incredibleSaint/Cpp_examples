#include <iostream>

template <typename T>
struct Node {
   T data;
   Node *left, *right;

   Node(T data_) : data(data_), left(nullptr), right(nullptr) {}
};

template <typename T, typename ... Args>
Node<T> *tree_get(Node<T> *top, Args&& ... args) {
    return (top->*...->*args);
}

auto left = &Node<int>::left;
auto right = &Node<int>::right;

int main() {
    Node<int> a(1), b(2), c(3), d(4), e(5), f(6), g(7);

    a.right = &b;
    a.left = &c;
    b.right = &d;
    b.left = &e;
    e.left = &f;
    f.right = &g;

    auto pa =&a;
    (pa->right)->left->right;

    Node<int> *res =  tree_get<int>(&a, right, left, left);
    std::cout << "Get node by tree_get(): " << res->data;
    return 0;
}
