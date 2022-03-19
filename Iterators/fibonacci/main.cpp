#include <iostream>
#include <utility>

//! Calculate fibonacci numbers

namespace fibs {
    struct fibonacci {};

    struct iter {
        int cur = 1, prev = 0;

        iter &operator++() {
            int tmp = cur;
            cur = cur + prev;
            prev = tmp;
            return *this;
        }

        int operator *() {return cur;}
        auto operator<=>(const iter&) const = default;
    };

    auto begin(fibonacci) { return iter{}; }
    iter end(fibonacci) { return iter{89, 55}; }
}


int main() {
    for (auto &&f : fibs::fibonacci()) {
        std::cout << f << " ";
    }
    return 0;
}
