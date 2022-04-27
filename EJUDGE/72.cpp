#include <iostream>
#include <map>

// L = { a1 a2 ... an an ... a2 a1 | ai ∈ { x, y}, n ≥ 1}

// Правила грамматики:
// S → xSx | ySy | xx | yy

std::multimap<std::string, std::string> g() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;
    x.first = "S"; x.second = "xSx";
    table.insert(x);
    x.first = "S"; x.second = "ySy";
    table.insert(x);
    x.first = "S"; x.second = "xx";
    table.insert(x);
    x.first = "S"; x.second = "yy";
    table.insert(x);

    return table;
}