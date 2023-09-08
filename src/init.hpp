#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stack>
#include <cmath>
#include <condition_variable>
using namespace std;
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC std("c++11")
const unsigned long long _BUFFER_SIZE_ = (unsigned long long)(pow(2, 25));
const string _VERSION_ = "v1.14.4";
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
    "end-loop"
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