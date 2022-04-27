#include <iostream>

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