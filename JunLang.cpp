#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <condition_variable>
using namespace std;
#define _VERSION_ "v1.13.2"
#define _DEFAULT_BUFFER_SIZE_ 1024
string identifiers[] = {
    "output",
    "wrap",
    "new",
    "set",
    "input",
    "addition",
    "subtraction",
    "multiplication",
    "division" 
};
struct Variable {
    long double value;
    string name;
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
bool isInteger(string x) {
    bool integer = true;
    for (int i = 0; i < strlen(x.c_str()); i++) {
        if (x[i] < '0' || x[i] > '9') {
            integer = false;
            break;
        }
    }
    return integer;
}
int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string fileName = string(argv[1]);
        int bufferSize;
        if (argc == 3) {
            bufferSize = atoi(string(argv[2]).c_str());
        }
        else {
            bufferSize = _DEFAULT_BUFFER_SIZE_;
        }
        char buffer[bufferSize];
        Variable variables[bufferSize];
        int variableCount = 0;
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "[ERROR] File cannot open.\n";
            exit(0);
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
                                cerr << "[ERROR] Undeclared variable.\n";
                            }
                        }
                        cout << string(*(it + 1)).substr(1, strlen((*(it + 1)).c_str()) - 2);
                        break;
                    }
                    else if (*it == identifiers[1]) {
                        cout << endl;
                    }
                    else if (*it == identifiers[2]) {
                        bool duplicate = false;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                duplicate = true;
                                break;
                            }
                        }
                        if (duplicate) {
                            cerr << "[ERROR] Duplicate variable name.\n";
                        }
                        variables[variableCount++].name = *(it + 1);
                        break;
                    }
                    else if (*it == identifiers[3]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                variables[i].value = atoi((*(it + 2)).c_str());
                                undeclared = false;
                                break;
                            }
                        }
                        if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                    else if (*it == identifiers[4]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                if (isInteger(*(it + 2))) {
                                    variables[i].value = atoi((*(it + 2)).c_str());
                                    undeclared = false;
                                    break;
                                }
                                else {
                                    undeclared = true;
                                    for (int j = 0; j <= variableCount; j++) {
                                        if (variables[j].name == *(it + 2)) {
                                            variables[i].value = variables[j].value;
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                    else if (*it == identifiers[4]) {
                    	bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                            	long double temp;
                            	cin >> temp;
                            	variables[i].value = temp;
                            	undeclared = false;
                            	break;
                            }
						}
						if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                    else if (*it == identifiers[5]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                if (isInteger(*(it + 2))) {
                                    variables[i].value += atoi((*(it + 2)).c_str());
                                    undeclared = false;
                                    break;
                                }
                                else {
                                    undeclared = true;
                                    for (int j = 0; j <= variableCount; j++) {
                                        if (variables[j].name == *(it + 2)) {
                                            variables[i].value += variables[j].value;
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                    else if (*it == identifiers[6]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                if (isInteger(*(it + 2))) {
                                    variables[i].value -= atoi((*(it + 2)).c_str());
                                    undeclared = false;
                                    break;
                                }
                                else {
                                    undeclared = true;
                                    for (int j = 0; j <= variableCount; j++) {
                                        if (variables[j].name == *(it + 2)) {
                                            variables[i].value -= variables[j].value;
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                    else if (*it == identifiers[7]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                if (isInteger(*(it + 2))) {
                                    variables[i].value *= atoi((*(it + 2)).c_str());
                                    undeclared = false;
                                    break;
                                }
                                else {
                                    undeclared = true;
                                    for (int j = 0; j <= variableCount; j++) {
                                        if (variables[j].name == *(it + 2)) {
                                            variables[i].value *= variables[j].value;
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                    else if (*it == identifiers[8]) {
                        bool undeclared = true;
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == *(it + 1)) {
                                if (isInteger(*(it + 2))) {
                                    variables[i].value /= atoi((*(it + 2)).c_str());
                                    undeclared = false;
                                    break;
                                }
                                else {
                                    undeclared = true;
                                    for (int j = 0; j <= variableCount; j++) {
                                        if (variables[j].name == *(it + 2)) {
                                            variables[i].value /= variables[j].value;
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (undeclared) {
                            cerr << "[ERROR] Undeclared variable.\n";
                        }
                        break;
                    }
                }
                else {
                    cerr << "[ERROR] Unknow identifier.\n";
                }
            }
        }
    }
    else {
        cout << "JunLang " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename] <bufferSize>" << endl;
    }
    return 0;
}
