#pragma once
#include "HashTable.h"
#include "sha1.h"

class Chat {
public:
    Chat();
    ~Chat();
    void reg(char* _login, char* _pass, int pass_length);
    bool login(char* _login, char* _pass, int pass_length);

private:
    HashTable* data;
    int data_count;
};


