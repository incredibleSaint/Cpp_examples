#include <iostream>

class TemplClass {
    uint32_t do_not_touch_this_from_outside = 40;
    uint32_t field;
public:
    template <typename T>
    void SetDoNotTouch(uint32_t v) {
        field = v;
    }

    void PrintDoNotTouch() {
        std::cout << "Do_not_touch_this_from_outside = " << do_not_touch_this_from_outside << std::endl;
    }
};
// -----------------------
struct MyStruct {};

template <>
void TemplClass::SetDoNotTouch<MyStruct>(uint32_t v) {
    field = v;
    do_not_touch_this_from_outside = 14; // In template specialization we can change private fields, how we want.
}

int main() {
    TemplClass tc;
    tc.SetDoNotTouch<bool>(8);
    tc.PrintDoNotTouch();

    std::cout << "Change private field which we shouldn't touch (from template specialization, "
                 "which we can do always)" << std::endl;

    tc.SetDoNotTouch<MyStruct>(0);

    tc.PrintDoNotTouch();

    return 0;
}
