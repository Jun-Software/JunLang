#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stack>
#include <cmath>
#include <condition_variable>
#include <filesystem>
using namespace std;
#pragma GCC std("c++17")
const string _VERSION_ = "v1.14.8";
const int _BUFFER_SIZE_ = 1024;
const string identifiers[] = {
    "output",
    "wrap",
    "new",
    "set",
    "input",
    "addition",
    "subtraction",
    "multiplication",
    "division",
    "equal",
    "greater",
    "less",
    "equal-or-greater",
    "equal-or-less",
    "not",
    "if",
    "end-if",
    "loop", 
    "end-loop",
    "note"
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
char buffer[_BUFFER_SIZE_];
Variable variables[_BUFFER_SIZE_];
stack<bool> ifFlag;
stack<bool> loopFlag;
stack<string> loopVariableName;
stack<streampos> loopLine;
int variableCount = 0;