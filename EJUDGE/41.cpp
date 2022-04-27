#include <iostream>
#include <string>
#include <cstring>

using std::string;

enum {TOKEN_LEN = 208};

class TokenPool
{
public:
    TokenPool(size_t n);
    ~TokenPool();
    TokenPool(const TokenPool&) = delete;
    TokenPool operator=(const TokenPool&);

    size_t token_length() const;
    void get_token(char *addr);
    void return_token(const char *addr); 
private:
    string *arr; // массив токенов
    bool *free_tokens; // массив, в котором ведётся учёт того, свободен ли токен
    size_t token_num;
};

TokenPool::TokenPool(size_t n) : arr(nullptr), free_tokens(nullptr), token_num(n) 
{
    try {
        arr = new string[token_num];
    } catch (const std::bad_alloc &e) {
        throw;
    }

    try {
        fill_by_different_strings(arr, token_num, TOKEN_LEN);
    } catch (const std::exception &e) {
        delete[] arr;
        throw;
    }

    try {
        free_tokens = new bool[token_num];
    } catch (const std::bad_alloc &e) {
        delete [] arr;
        throw;
    }

    for (size_t i = 0; i < token_num; i++) {
        free_tokens[i] = true;
    }
}

size_t TokenPool::token_length() const
{
    return TOKEN_LEN;
};

void TokenPool::get_token(char *addr)
{
    for (size_t i = 0; i < token_num; i++) {
        if (free_tokens[i]) {
            strcpy(addr, arr[i].c_str());
            free_tokens[i] = false;
            return;
        }
    }
    throw std::logic_error("Error! No free tokens");
};

void TokenPool::return_token(const char *addr)
{
    for (size_t i = 0; i < token_num; i++) {
        if (strcmp(addr, arr[i].c_str()) == 0 && !free_tokens[i]) {
            free_tokens[i] = true;
            return;
        }
    }
    throw std::logic_error("Error! Bad token");
};

TokenPool::~TokenPool() {
    delete [] arr;
    delete [] free_tokens;
}