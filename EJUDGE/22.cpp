class A
{
  public: void f2();
};

class B : public A
{
public:
    void f1() {};
private:
    void f2() {};
    void f3() {};
};

class C : B
{ public:
    void good1() { f1(); }
    void good2() { f3(); }
    void f();
};

void good1() { B b; b.f1(); }
bool good2() { B b; A *p = &b; return p != 0; }

#ifdef BAD1
void C::f() { f2(); }
void f() { &B::f2; }
#endif

#ifdef BAD2
void f() { B b; b.f3(); }
#endif

int
main() { 
    return 0;
}