#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num, last;

    while (std::cin >> num) {
        numbers.push_back(num);
    }
    last = num;
    
    int k = 0;
    for (std::vector<int>::size_type i = 0; i < numbers.size(); i++) {
        if (numbers[i] > last) {
            k++;
        }
    }

    if (numbers.size() != 0) {
        std::cout << k << std::endl;
    }

    return 0;
}