#include <map>
#include <string>

// L1:
// {c (a|b)^n, n ≥ 0}
// L2:
// {(a|b)^n c, n ≥ 0}

std::multimap<std::string, std::string> g1() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;

    x.first = "S"; x.second = "cH";
    table.insert(x);
    x.first = "H"; x.second = "aH";
    table.insert(x);
    x.first = "H"; x.second = "bH";
    table.insert(x);
    x.first = "H"; x.second = "_";
    table.insert(x);

    return table;
};

std::multimap<std::string, std::string> g2() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;

    x.first = "S"; x.second = "aS";
    table.insert(x);
    x.first = "S"; x.second = "bS";
    table.insert(x);
    x.first = "S"; x.second = "c";
    table.insert(x);

    return table;
};