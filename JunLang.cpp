#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <condition_variable>
using namespace std;
#define _VERSION_ "1.10"
#define _DEFAULT_BUFFER_SIZE_ 1024
string identifiers[] = {
    "output",
    "wrap",
    "new",
    "set"
};
struct Variable {
    int value;
    string name;
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
struct DuplicateVariableName : public exception {
    const char * what () const throw () {
        return "Duplicate variable name.";
    }
};
struct UndeclaredVariable : public exception {
    const char * what () const throw () {
        return "Undeclared variable.";
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
        Variable variables[bufferSize];
        int variableCount = 0;
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
                        break;
                    }
                }
                if (!unknow) {
                    if (*it == identifiers[0]) {
                        if ((*(it + 1))[0] != '"') {
                            bool variable = false;
                            for (int i = 0; i <= variableCount; i++) {
                                if (variables[i].name == *(it + 1)) {
                                    cout << variables[i].value;
                                    variable = true;
                                    break;
                                }
                            }
                            if (!variable) {
                                throw UndeclaredVariable();
                            }
                        }
                        cout << string(*(it + 1)).substr(1, strlen((*(it + 1)).c_str()) - 2);
                        break;
                    }
                    if (*it == identifiers[1]) {
                        cout << endl;
                    }
                    if (*it == identifiers[2]) {
                        bool duplicate = false;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                duplicate = true;
                                break;
                            }
                        }
                        if (duplicate) {
                            throw DuplicateVariableName();
                        }
                        variables[variableCount++].name = *(it + 1);
                        break;
                    }
                    if (*it == identifiers[3]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                variables[i].value = atoi((*(it + 2)).c_str());
                                undeclared = false;
                                break;
                            }
                        }
                        if (undeclared) {
                            throw UndeclaredVariable();
                        }
                        break;
                    }
                }
                else {
                    throw UnknowIdentifier();
                }
            }
        }
    }
    catch (logic_error) {
        cout << "JunLang " << 'v' << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename] <bufferSize>" << endl;
    }
    return 0;
}
