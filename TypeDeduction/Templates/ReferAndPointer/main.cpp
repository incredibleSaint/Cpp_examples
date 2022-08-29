#include <iostream>
#include <boost/type_index.hpp>

//Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
//1. If expr’s type is a reference, ignore the reference part.
//2. Then pattern-match expr’s type against ParamType to determine T.
template <typename T>
void ref_func(T &param) {
  using boost::typeindex::type_id_with_cvr;

  std::cout << "T =     "
            << type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << "Param = "
            << type_id_with_cvr<decltype(param)>().pretty_name() << "\n\n";
}

template <typename T>
void ptr_func(T *param) {
  using boost::typeindex::type_id_with_cvr;
  param = nullptr;
  std::cout << "T =     "
            << type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << "Param = "
            << type_id_with_cvr<decltype(param)>().pretty_name() << "\n\n";
}

int main() {
  std::cout << "References\n";
  int x = 2;
  const int cx = 2;
  const int &rx = 2;
  int const &crx = x;
  ref_func(x);
  ref_func(cx);
  ref_func(rx);

  int *px = &x;
  int const *pcx = &x;
  int * const cpx = &x;
  *cpx = 0;
  std::cout << "\nPointers\n";
  ptr_func(&x);
  ptr_func(px);
  ptr_func(pcx);
  ptr_func(cpx); // why is just T = int, param = int * (without const)?!
  return 0;
}
