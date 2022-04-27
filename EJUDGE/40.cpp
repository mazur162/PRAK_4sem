#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <stdexcept>

class Error
{
public:
    Error(): msg("") {}
    Error(const std::string &s): msg(s) {}
    Error(const Error &oth): msg(oth.msg) {}
    Error &operator=(const Error &oth) = delete;
    ~Error() {}
    const std::string &message() const { return msg; }
private:
    const std::string msg;
};