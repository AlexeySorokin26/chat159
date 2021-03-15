#pragma once
#include <string>
#include <iostream>
#include <vector>

class HashTable { 
private:

    enum class enPairStatus {
        free,
        engaged,
        deleted
    };

    struct Pair {

        Pair() : login(0) {
            hash = 0;
            status = enPairStatus::free;
        }
        Pair(char* _login, unsigned int* _hash) :
            login(_login),
            hash(_hash),
            status(enPairStatus::engaged) {
        }

        char* login;
        unsigned int* hash;

        enPairStatus status;
    };

    int hash_func(int val);
    int hash_func(char* _login, int offset);
    void resize();

    std::vector<Pair> array;

    int mem_size;
    int count;
public:
    HashTable();
    ~HashTable();
    void add(char* _login, unsigned int* _hash);
    std::vector<Pair> getArray();


};


