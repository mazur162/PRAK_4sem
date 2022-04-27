#include <iostream>

template <typename C>
void g(const C& c) {
    if (c.size() >= 3) {
        typename C::const_reverse_iterator i = c.rbegin();
        std::cout << *i + *(++i) + *(++i) << std::endl;
    }
}