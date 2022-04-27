#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// S → AS | B
// A → b | c
// B → dBf | a | ε

// (b | c)^n + (d)^k + (a | _) + (f)^k

class Parser {
public:
    Parser() = default;
    bool parse(std::istream &stream);
private:
    char c;
    std::istream *stream_ptr;
    void match(char x);
    void A(), B(), S();
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
    if (!(*stream_ptr)) {
        return;
    }
    if (c == 'b' || c == 'c') {
        A();
        S();
    } else {
        B();
    } 
}

void Parser::A() {
    if (c == 'b') {
        match('b');
    } else if (c == 'c') {
        match('c');
    } else throw std::logic_error("Bad symbol");
}

void Parser::B() {
    if (!(*stream_ptr)) {
        return;
    }
    if (c == 'd') {
        match('d');
        B();
        match('f');
    } else if (c == 'a') {
        match('a');
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
