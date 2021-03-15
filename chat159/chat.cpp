#include "chat.h"

Chat::Chat() {
	data_count = 0;
	data = new HashTable;
}

Chat::~Chat() {
	if (data)
		delete data;
	data = nullptr;
}

void Chat::reg(char* _login, char* _pass, int pass_length) {
	data_count++;
	data->add(_login, sha1(_pass, pass_length));
}

bool Chat::login(char* _login, char* _pass, int pass_length) {
    int counter = 0;
    bool foundLogin = false;
    for (; counter < data_count; ++counter) {
        if (strcmp(_login, data->getArray()[counter].login) == 0) {
            foundLogin = true;
            break;
        }
    }
    if (foundLogin) {
        uint* digest = sha1(_pass, pass_length);
        bool cmpHashes = !memcmp(data->getArray()[counter].hash, digest, sizeof(digest));
        delete[] digest;
        if (cmpHashes)
            return true;
        else
            return false;
    }
    return false;
}
