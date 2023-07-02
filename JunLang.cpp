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
    "output"
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
            cout << "[Error] File cannot open." << endl;
        }
        while (file.good()) {
            file.getline(buffer, sizeof(buffer));
            vector<string> vec(split(string(buffer), ' '));
            for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
                for (int i = 0; i < (sizeof(identifiers) / sizeof(string)); i++) {
                    if (identifiers[i] != *it) {
                        if (*(it - 1) == identifiers[0]) {
                            cout << *it << endl;
                        }
                        else {
                            cout << "[Error] Unknow identifiers: " << *it << endl;
                        }
                    }
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
