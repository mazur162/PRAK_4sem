#include <iostream>
#include <map>

// L = { α c β c γ c | α, β, γ ∈ { a, b }* (т.е. α, β, γ - любые цепочки из a и b) }

// Правила грамматики:
// S → AAA
// A → aA | bA | c

std::multimap<std::string, std::string> g() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;
    x.first = "S"; x.second = "AAA";
    table.insert(x);

    x.first = "A"; x.second = "aA";
    table.insert(x);
    x.first = "A"; x.second = "bA";
    table.insert(x);
    x.first = "A"; x.second = "c";
    table.insert(x);

    return table;
}