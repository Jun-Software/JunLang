void set(vector<string>::iterator it) {
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            if (isInteger(*(it + 2))) {
                undeclared = false;
                variables[i].value = atoi((*(it + 2)).c_str());
                break;
            }
            else {
                undeclared = true;
                for (int j = 0; j <= variableCount; j++) {
                    if (variables[j].name == *(it + 2)) {
                        undeclared = false;
                        variables[i].value = variables[j].value;
                        break;
                    }
                }
            }
        }
    }
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}