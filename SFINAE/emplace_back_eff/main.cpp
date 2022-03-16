/*
 * Emplace vs push_back: emplace part.
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
public:
	Stack() = default;
	Stack(const Stack<T> &) = delete;
	Stack<T> &operator=(const Stack<T> &) = delete;
	
	//    template <typename T>
	struct StackElem {
		T elem;
		StackElem *next;
		
		template<typename... Args>
		StackElem(StackElem *n, Args &&... args)
				: elem(std::forward<Args>(args)...), next(n) {
			std::cout << "StackElem ctor" << std::endl;
		}
		
		~StackElem() { std::cout << "StackElem dtor" << std::endl; }
	};

private:
	struct StackElem *top_ = nullptr;

public:
	template <typename... Args>
	void emplace_back(Args &&...);
	
	~Stack();
};

template <typename T>
template <typename... Args>
void Stack<T>::emplace_back(Args &&... args) {
	top_ = new StackElem(top_, std::forward<Args>(args)...);
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
		s.emplace_back(100);
	}
	return 0;
}
