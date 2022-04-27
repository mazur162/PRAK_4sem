#include <iostream>

template <typename IteratorT, typename BracketT>
bool check(IteratorT begin, IteratorT end, BracketT open, BracketT close) {
    bool flag = false; // флаг для проверки того, 
    // что открывающаяся скобка встретилась раньше закрывающейся
    int balance = 0;
    for (IteratorT i = begin; i != end; ++i) {
        if (*i == open) {
            flag = true;
            balance++;
        }
        if ((*i == close) && (flag == true)) {
            balance--;
        }
    }
    if ((balance != 0) || (flag == false)) {
        return false;
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    if (str.empty()) {
        return 0;
    } else {
        if (check <std::string::iterator, char> (str.begin(), str.end(), '(', ')')) {
            std::cout << "Correct" << std::endl;
        } else {
            std::cout << "Incorrect" << std::endl;
        }
    }
    return 0;
}