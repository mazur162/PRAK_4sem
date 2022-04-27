#include <map>
#include <string>

bool increased(const std::map<std::string, std::string> & table) {
    bool answer = true;
    std::map<std::string, std::string>::const_iterator i;
    for (i = table.begin(); i != table.end(); ++i) {
    if ((i->second).find(i->first) == std::string::npos) {
            answer = false;
            break;
        }
    }
    return answer;
}