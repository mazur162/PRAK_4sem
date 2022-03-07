class B: public A // наследование
{
public:
    // конструктор преобразования (без параметров / с 1 параметром)
    B(int a = 0) :  A(a + 1), z(a) {
        z += 2;
    }

    // конструктор копирования
    B(B& b) : A(b.z), z(b.z) {}
private:
    int z;
};