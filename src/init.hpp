/**
 * Entry function of the program
 * By lemonorangeapple
**/
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
#pragma GCC std("c++11")
// Version of the program
const string _VERSION_ = "v1.15.00";
// Buffer size
const int _BUFFER_SIZE_ = 1024;
// All identifiers.
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
// Variable struct
struct Variable {
    long double value;
    string name;
};
// split function
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
// isInteger function
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
// Const variables
char buffer[_BUFFER_SIZE_];
Variable variables[_BUFFER_SIZE_];
stack<bool> ifFlag;
stack<bool> loopFlag;
stack<string> loopVariableName;
stack<streampos> loopLine;
int variableCount = 0;