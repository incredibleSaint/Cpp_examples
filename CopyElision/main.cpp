#include <cstring>
#include <iostream>

template <class T> class MyArray
{
    T* m_Data;
    int m_Size;

public:
    MyArray() : m_Size(0), m_Data(nullptr) {
    }

    MyArray(int size) :
                        m_Data(new T[size]),
                        m_Size(size)
                        { // перепутана местами инициализация
    }

    ~MyArray() {
        delete m_Data; // size = h
    }

    void SetSize(int size) {
        delete m_Data;
        m_Data = new T[size];
        m_Size = size;
    }

    int GetSize() const {
        return m_Size;
    };

    T& operator[] (int index) {
        return m_Data[index];
    }

    MyArray& operator= (MyArray src) {
        SetSize(src.GetSize());
        std::memcpy(m_Data, src.m_Data, sizeof(T)*m_Size);
        return *this;
    }

    // Проблема решается с помощью использования copy-constructor
    MyArray(const MyArray& a) : m_Size(a.GetSize()), m_Data(new T[a.GetSize()]) {
//        SetSize(a.GetSize());
        std::memcpy(m_Data, a.m_Data, sizeof(T) * m_Size);
    }
};

typedef MyArray<int> IntArray;

int Sum(IntArray ar)
{
    int sum = 0;
    for (int i=0; i < ar.GetSize(); i++) {
        sum += ar[i];
    }

    return sum;
}

int main(int argc, char* argv[])
{
    // simple usage
    char source[] = "once upon a midnight dreary...", dest[4];
    std::memcpy(dest, source, sizeof dest);
    std::cout << "dest[4] = { ";
    for (char c : dest)
        std::cout << "'" << c << "', ";
    std::cout << "};\n";

    int array_size = 1e6;
    IntArray *A = new IntArray(10); // 1й объект с адресом n
    for (int i=0; i<10; i++) {
        (*A)[i] = i<<3;
    }

    IntArray B = *A; // 2й объект с адресом n
    MyArray<int> C;

    int sum = Sum(B); // cюда объект копируется, поэтому получается 3й объект с таким же адресом
    int a = 1;
    delete A;
}