#include <iostream>
class A
{
public:
    A(int a = 0) : x(a + 1) {}
    int get() const { return x; }
private:
    int x;
};
class B: public A // наследование
{
public:
    // конструктор преобразования (без параметров / с 1 параметром)
    B(int a = 0) :  A(a + 1), z(a) {
        z += 2;
    }

    // конструктор копирования
    B(B& b) : A(b.z) {}
private:
    int z;
};

int main()
{
    int x, y;
    std::cin >> x >> y; // 5 -1
    B b(x);
    A *p = &b;
    B b2 = b;
    A *p2 = &b2;
    std::cout << p->get() << " " << p2->get() << " " << y << std::endl; // 7 8 -1
    return 0;
} 
