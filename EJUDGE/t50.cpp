#include <iostream>

template <typename T, typename U>
void f(T, U) { std::cout << "f-T-U" << std::endl; }

template <typename U>
void f(short, U) { std::cout << "f-short-U" << std::endl; }

template <typename T>
void f(T x, int) { std::cout << "f-T-int" << std::endl; }

template <typename T>
void f(T *, int) { std::cout << "f-T*-int" << std::endl; }

template <typename T, typename U>
void f(T, U, U) { std::cout << "f-T-U-U" << std::endl; }

template <>
void f(int, int) { std::cout << "f-int-int" << std::endl; }

void f(int, int) { std::cout << "int-int" << std::endl; }

void f(short, short) { std::cout << "short-short" << std::endl; }

// insert arguments for each call
int main()
{
    f('a', 'b');    // f-T-U
    f(static_cast<std::string> ("str"), static_cast<int> (1));    // f-T-int
    f("str", static_cast<int> (1));     // f-T*-int
    f('a', 'b', 'c');    // f-T-U-U
    f(static_cast<short> (2), 'a');    // f-short-U
    f(static_cast<short> (2), static_cast<short> (2));    // short-short
    f(static_cast<int> (1), static_cast<int> (1));    // int-int
}
