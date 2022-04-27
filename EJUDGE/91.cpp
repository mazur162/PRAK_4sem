#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// S → bS | aAB
// A → bcA | ccA | ε
// B → cbB | ε

/* 
Проверим, применим ли метод рекурсивного спуска с помощью пошагового алгоритма:
1) first(bS) ⋂ first(aAB) = ∅ OK
   first(bcA) ⋂ first(ccA) = ∅ OK

2) Имеется только 1 выход в ε OK

3) first(S) = follow(B) + follow(A) = {a, b, c}
   first(S) ⋂ follow(S) = {a, b} ⋂ {a, b, c} = {a, b} != ∅ !!! =>
   => метод рекурсивного спуска неприменим
*/ 

// (b)^n + a + (bc | cc)^k + (cb)^m

// Эквивалентная грамматика, к которой метод рекурсивного спуска применим:
// S → bS | aA
// A → bcA | cC | ε
// B → cbB | ε
// C → cA | bB

class Parser {
public:
    Parser() = default;
    bool parse(std::istream &stream);
private:
    char c;
    std::istream *stream_ptr;
    void match(char x);
    void A(), B(), C(), S();
};

bool Parser::parse(std::istream &stream) {
    stream_ptr = &stream;
    stream >> c;
    try {
        S();
    } catch (const std::exception &e) {
        return false;
    }

    if (stream) {
        return false;
    }
    return true;
}

void Parser::match(char x) {
    if (*stream_ptr && c == x) {
        *stream_ptr >> c;
    } else throw std::logic_error("Bad symbol");
}

void Parser::S() {
    if (c == 'b') {
        match('b');
        S();
    } else if (c == 'a') {
        match('a');
        A();
    } else throw std::logic_error("Bad symbol");
}

void Parser::A() {
    if (!(*stream_ptr)) {
        return;
    }
    if (c == 'b') {
        match('b');
        match('c');
        A();
    } else if (c == 'c') {
        match('c');
        C();
    } else throw std::logic_error("Bad symbol");
}

void Parser::B() {
    if (!(*stream_ptr)) {
        return;
    }
    if (c == 'c') {
        match('c');
        match('b');
        B();
    }
}

void Parser::C() {
    if (c == 'c') {
        match('c');
        A();
    } else if (c == 'b') {
        match('b');
        B();
    }
}

int main() {
    std::string str;
    while (getline(std::cin, str)) {
        std::stringstream stream;
        stream.str(str);
        Parser p;
        if (p.parse(stream)) {
            std::cout << "YES" <<std::endl;
        } else {
            std::cout << "NO" <<std::endl;
        }
    }
    return 0;
}
