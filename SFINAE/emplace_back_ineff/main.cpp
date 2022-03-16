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

        StackElem(T e, StackElem *n)
						: elem(e), next(n) {
			std::cout << "StackElem ctor" << std::endl;
		}
		
        ~StackElem() { std::cout << "StackElem dtor" << std::endl; }
    };

    struct StackElem *top_ = nullptr;

public:
    void push_back(const T &s);

    ~Stack();
};

template <typename T>
void Stack<T>::push_back(const T &elem) {
    top_ = new StackElem(elem, top_);
}

template <typename T>
Stack<T>::~Stack() {
	std::cout << "Stack dtor" << std::endl;
	
    struct StackElem *curr_top = top_;
    while (curr_top != nullptr) {
        struct StackElem *tmp = curr_top->next;
        delete curr_top;
        curr_top = tmp;
    }
}

int main() {
    Stack<Heavy> s;
    for (int i = 0; i < 1; i++) {
        s.push_back(Heavy(100));
    }
    return 0;
}
