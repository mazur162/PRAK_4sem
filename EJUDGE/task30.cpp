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

#include <iostream>

void A::f() {
    std::cout << "A::f" << std::endl;
}

void A::g() {
    std::cout << "A::g" << std::endl;
}

void B::f() {
    std::cout << "B::f" << std::endl;
}

void B::g() {
    std::cout << "B::g" << std::endl;
}

C::C(): val(new A) {
}

C::~C() {
    delete val;
}

void C::f() {
    std::cout << "C::f" << std::endl;
}

void C::h() {
    std::cout << "C::h" << std::endl;
}


int main() {
    std::cin >> x;

    A * a = new A();
    A * b = new B();
    A * c = new C();
    // Должно вывести:
    a->f(); // A::f OK
    a->g(); // A::g OK

    b->f(); // B::f OK
    b->g(); // B::g OK

    c->f(); // C::f OK
    c->g(); // B::g !!! A::g

    c->h(); // A::h OK

    delete a;
    delete b;
    delete c;

    std::cout << x << std::endl;
    return 0;
}
