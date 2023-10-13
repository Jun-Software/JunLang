/**
 * Input function
 * By lemonorangeapple
**/
void input(vector<string>::iterator it) {
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
        cerr << "[Error] Variable undeclared." << endl;
    }
}