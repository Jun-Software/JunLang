/**
 * Init function of the program
 * By lemonorangeapple
**/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stack>
#include <cmath>
#include <condition_variable>
#include <functional>
using namespace std;
#pragma GCC std("c++11")
// Version of the program
const string _VERSION_ = "b1.17.10";
// Buffer size
const int _BUFFER_SIZE_ = 1024;
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
// Variables
char buffer[_BUFFER_SIZE_];
stack<bool> ifFlag;
stack<bool> loopFlag;
stack<bool> funcFlag;
map<string, int> funcStartMap;
map<string, int> funcEndMap;
map<string, int> funcUseMap;
stack<string> loopVariableName;
stack<string> funcName;
stack<string> fileRun;
stack<streampos> loopLine;