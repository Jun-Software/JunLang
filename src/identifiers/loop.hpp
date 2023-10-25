/**
 * Loop function
 * By lemonorangeapple
**/
void loop(vector<string>::iterator it, ifstream &file) {
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            undeclared = false;
            loopVariableName.push(string(*(it + 1)));
            if (variables[i].value == 0) {
                loopFlag.push(false);
            }
            else {
                loopLine.push(int(file.tellg()) - 2);
                loopFlag.push(true);
            }
            break;
        }
    }
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}