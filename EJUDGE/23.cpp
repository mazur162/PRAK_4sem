class B: public A
{
public:
    void f() { printf("B::f\n"); }
    void f2() { printf("B::f2\n"); A::f2(); }
};