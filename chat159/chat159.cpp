#include <iostream>
#include "chat.h"


int main() {

    char log1[] = "alexey";
    char pass1[] = "russian";
    char log2[] = "alexey1";
    char pass2[] = "russian1";

    Chat chat;
    chat.reg(log1, pass1, sizeof(pass1));
    chat.reg(log2, pass2, sizeof(pass2));
    std::cout << chat.login(log1, pass1, sizeof(pass1)) << std::endl;
    std::cout << chat.login(log2, pass2, sizeof(pass2)) << std::endl;
    std::cout << chat.login(log1, pass2, sizeof(pass1)) << std::endl;
    std::cout << chat.login(log2, pass1, sizeof(pass1)) << std::endl;

    return 0;
}


