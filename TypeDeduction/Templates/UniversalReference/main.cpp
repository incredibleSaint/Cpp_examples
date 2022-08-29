#include <iostream>
#include <boost/type_index.hpp>

// Param is universal reference:
// 1. If expr is an lvalue, both T and ParamType are deduced to be lvalue references.
//      That’s doubly unusual. First, it’s the only situation in template type deduction
//      where T is deduced to be a reference. Second, although ParamType is declared
//      using the syntax for an rvalue reference, its deduced type is an lvalue reference.
// 2. If expr is an rvalue, the “normal” (i.e., Case 1) rules apply.
template <typename T>
void func(T &&param) {
  using boost::typeindex::type_id_with_cvr;

  std::cout << "T =     "
            << type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << "Param = "
            << type_id_with_cvr<decltype(param)>().pretty_name() << "\n\n";
}

int main() {
  int x = 2;
  const int cx = 2;
  const int &rx = 2;

  func(x); // T - int &,       param - int &
  func(cx);// T - const int &, param - const int &
  func(rx);// T - const int &, param - const int &
  func(22);// T - int,         param - int &&
  return 0;
}
