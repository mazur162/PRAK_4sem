#include <iostream>
#include <string>

// Дана грамматика:
// S → aBA | ε
// B → bSA
// AA → c

// => слова имеют вид: (ab)^n c^n

int main() {
    std::cout << 0 << std::endl;
    std::cout << 2 << std::endl;

    std::string str;
    std::getline(std::cin, str);
    while (!std::cin.eof()) {
        if (str.empty()) {
            std::cout << "YES" << std::endl;
        } else {
            bool answer = true;
            int n1 = 0, n2 = 0;
            for (size_t i = 0; i < str.size(); i++) {
                // если символы не из алфавита, то сразу NO
                if (str[i] != 'a' && str[i] != 'b' && str[i] != 'c') {
                    answer = false;
                    break;
                }
                if (str[i] == 'a') {
                    if (str[i + 1] != 'b') {
                        answer = false;
                        break;
                    }
                    n1++;
                }
                if (str[i] == 'b') {
                    if ((str[i + 1] != 'a' || str[i + 1] != 'c') && (i == 0)) {
                        answer = false;
                        break;
                    }
                }
                if (str[i] == 'c') {
                    if (i != str.size() - 1) {
                        if (str[i + 1] != 'c') {
                            answer = false;
                            break;
                        }
                    }
                    n2++;
                }
            }
            if (n1 != n2) {
                answer = false;
            }
            if (answer) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
        std::getline(std::cin, str);
    };

    return 0;
}