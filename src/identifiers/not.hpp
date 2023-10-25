/**
 * Not function
 * By lemonorangeapple
**/
void _not(vector<string>::iterator it) {
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            undeclared = true;
            for (int j = 0; j <= variableCount; j++) {
                if (variables[j].name == *(it + 2)) {
                    variables[j].value = !((bool)(variables[i].value));
                    undeclared = false;
                    break;
                }
            }
        }
        break;
    }
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}