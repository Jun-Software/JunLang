void _if(vector<string>::iterator it) {
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            if (variables[i].value == 0) {
                ifFlag.push(false);
            }
            else {
                ifFlag.push(true);
            }
            undeclared = false;
            break;
        }
    }
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}