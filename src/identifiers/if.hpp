#include "../init.hpp"
void _if(vector<string>::iterator it) {
    bool variable = false;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            if (variables[i].value == 0) {
                ifFlag.push(false);
            }
            else {
                ifFlag.push(true);
            }
            variable = true;
            break;
        }
    }
    if (!variable) {
        cerr << "[ERROR] Undeclared variable.\n";
    }
}