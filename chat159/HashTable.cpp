#include "HashTable.h"

HashTable::HashTable() {
    count = 0;
    mem_size = 8;
    array.resize(mem_size);
    //array = new Pair[mem_size];

}
HashTable::~HashTable() {
    /* 
    if(array)
        delete[] array;
    array = nullptr;
    */
}

void HashTable::add(char* _login, unsigned int* _hash) {
    int index = -1, i = 0;
    // search a free position 
    for (; i < mem_size; i++) {
        index = hash_func(_login, i);
        if (array[index].status == enPairStatus::free) {
            // find a free position then take it
            break;
        }
    }
    /*
    if (i >= mem_size) return; // if no space then quit
    array[index] = Pair(_login, _hash);
    */

    if (i >= mem_size) {
        resize();
        add(_login, _hash);
    }
    else {
        array[index] = Pair(_login, _hash); // otherwise take it
        count++;
    }
    
}

std::vector<HashTable::Pair> HashTable::getArray() {
    return array;
}

void HashTable::resize() {
    std::vector<Pair> oldArray = array;     // take old array
    int oldSize = mem_size;
    mem_size *= 2;                          // increase a size twice

    array.resize(mem_size);                 // allocate new memory

    for (int i = 0; i < oldSize; ++i) {
        Pair current = oldArray[i];
        if (current.status == enPairStatus::engaged)
            add(current.login, current.hash);
    }

}

int HashTable::hash_func(char* _login, int offset) {
    int sum = 0, i = 0;
    for (; i < strlen(_login); i++) {
        sum += _login[i];
    }
    return (sum % mem_size + offset * offset) % mem_size;
}

int HashTable::hash_func(int val) {
    const double A = 0.7;
    const int M = 10;
    return int(M * (A * val - int(A * val)));
}
