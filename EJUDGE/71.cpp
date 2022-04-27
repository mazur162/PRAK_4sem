#include <iostream>
#include <map>
#include <string>
#include <cstring> 

int grammar_type(const std::multimap<std::string, std::string> & g) {
    int type;

    bool grammar_flag = false;
    std::map<std::string, std::string>::const_iterator i;
    for (i = g.begin(); i != g.end(); i++) {
        for (size_t j = 0; j < i->first.size(); j++) {
            if (isupper((i->first)[j])) {
                grammar_flag = true;
                break;
            }
        }
    } // если в левой части есть большие буквы - тогда это грамматика (минимум - 0 тип)
    if (!grammar_flag) {
        return -1;
    }

    // НАДО ИСПРАВИТЬ: неукорачивающая еще S -> eps, когда S нет в правых частях
    for (i = g.begin(); i != g.end(); i++) {
        if ((i->first).length() > (i->second).length()) { // укорачивающая
            return 0;
        }
    }

    return type;

}

int main() {
    std::multimap<std::string, std::string> table;
    std::pair<std::string, std::string> x;

    x.first = "S"; x.second = "";
    table.insert(x);
    x.first = "S"; x.second = "aBCd";
    table.insert(x);
    x.first = "BC"; x.second = "bc";
    table.insert(x);

    std::cout << grammar_type(table) << std::endl;
    return 0;
}
