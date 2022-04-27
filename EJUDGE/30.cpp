#include <iostream>

int x;

class A {
public:
    A();
    virtual ~A();

    virtual void f();
    virtual void g();
    void h();
};

class B : public A {
public:
    void f();
    void g();
};

class C : public B {
public:
    C (const C&);
    C& operator= (const C&);
    C();

    void h();
    void f();
    ~C();
private:
    A *val;
};

void A::h() {
    std::cout << "A::h" << std::endl;
}

A::A() {}
A::~A() {}
