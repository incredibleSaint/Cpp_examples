#include <iostream>
#include <boost/type_index.hpp>

// Case 3. ParamType is Neither a Pointer nor a Reference
//1. As before, if expr’s type is a reference, ignore the reference part.
//2. If, after ignoring expr’s reference-ness, expr is const, ignore that, too. If it’s
//  volatile, also ignore that. (volatile objects are uncommon. They’re generally
//  used only for implementing device drivers. For details, see Item 40.)
template <typename T>
void func(T param) {
  using boost::typeindex::type_id_with_cvr;

  std::cout << "T =     "
            << type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << "Param = "
            << type_id_with_cvr<decltype(param)>().pretty_name() << "\n\n";
}

int main() {
  int x = 2;
  const int cx = 2;
  const volatile int &rx = x;

  func(x); // T - int, param - int
  func(cx);// T - int, param - int
  func(rx);// T - int, param - int
  func(22);// T - int, param - int
  return 0;
}