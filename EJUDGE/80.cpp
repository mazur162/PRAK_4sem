#include <map>
#include <string>

// G1:
// S → Sabc | d
// G2:
// S → aS | Sb | a

std::multimap<std::string, std::string> g3() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;

    x.first = "S"; x.second = "Hc";
    table.insert(x);
    x.first = "S"; x.second = "d";
    table.insert(x);
    x.first = "H"; x.second = "Bb";
    table.insert(x);
    x.first = "B"; x.second = "Sa";
    table.insert(x);

    return table;
};

std::multimap<std::string, std::string> g4() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;
    
    x.first = "S"; x.second = "H_";
    table.insert(x);
    x.first = "S"; x.second = "C_";
    table.insert(x);
    x.first = "H"; x.second = "Ha";
    table.insert(x);
    x.first = "H"; x.second = "a";
    table.insert(x);
    x.first = "C"; x.second = "Hb";
    table.insert(x);
    x.first = "C"; x.second = "Cb";
    table.insert(x);

    return table;

};