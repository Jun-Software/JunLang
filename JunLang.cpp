#include <iostream>
#include <stdlib.h>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <condition_variable>
using namespace std;
#define _VERSION_ "1.00"
#define _DEFAULT_BUFFER_SIZE_ 1024
string identifiers[] = {
    "output",
    "wrap"
};


struct UnknowIdentifier : public exception {
    const char * what () const throw () {
        return "Unknow identifier.";
    }
};
struct FileCannotOpen : public exception {
    const char * what () const throw () {
        return "File cannot open.";
    }
};
vector<string> split(string str, char delim) {
    stringstream ss(str);
    string item;
    vector<string> result;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            result.push_back(item);
        }
    }
    return result;
}
int main (int argc, char* argv[]) {
    try {
        string fileName = string(argv[1]);
        int bufferSize;
        try {
            bufferSize = atoi(string(argv[2]).c_str());
        }
        catch (logic_error) {
            bufferSize = _DEFAULT_BUFFER_SIZE_;
        }
        char buffer[bufferSize];
        ifstream file(fileName);
        if (!file.is_open()) {
            throw FileCannotOpen();
        }
        while (file.good()) {
            file.getline(buffer, sizeof(buffer));
            vector<string> vec(split(string(buffer), ' '));
            for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
                bool unknow = true;
                for (int i = 0; i < (sizeof(identifiers) / sizeof(string)); i++) {
                    if (identifiers[i] == *it) {
                        unknow = false;
                    }
                }
                if (!unknow) {
                    if (*it == identifiers[0]) {
                        cout << *(it + 1);
                        break;
                    }
                    if (*it == identifiers[1]) {
                        cout << endl;
                    }
                    // TODO =====================================================================================================
                }
                else {
                    throw UnknowIdentifier();
                }
            }
        }
    }
    catch (logic_error) {
        cout << "JunLang " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename] <bufferSize>" << endl;
    }
    return 0;
}
