#include <iostream>
#include <map>

// Построить приведенную грамматику, эквивалентную данной КС-грамматике:
// S → aAB | E
// A → dDA | ε
// B → bE | f
// C → cAB | dSD | a // недостижимый
// D → eA
// E → fA | g

std::multimap<std::string, std::string> g() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;
    
    x.first = "S"; x.second = "aAB";
    table.insert(x);
    x.first = "S"; x.second = "E";
    table.insert(x);
    x.first = "A"; x.second = "dDA";
    table.insert(x);
    x.first = "A"; x.second = "";
    table.insert(x);
    x.first = "B"; x.second = "bE";
    table.insert(x);
    x.first = "B"; x.second = "f";
    table.insert(x);
    x.first = "D"; x.second = "eA";
    table.insert(x);
    x.first = "E"; x.second = "fA";
    table.insert(x);
    x.first = "E"; x.second = "g";
    table.insert(x);

    return table;
}