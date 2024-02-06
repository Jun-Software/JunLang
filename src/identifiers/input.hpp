/**
 * Input function
 * By lemonorangeapple
**/
void input(vector<string>::iterator it, ifstream &file) {
    // Check if variable is already declared
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        // If variable is found, assign value to it
        if (variables[i].name == *(it + 1)) {
            long double temp;
            cin >> temp;
            variables[i].value = temp;
            undeclared = false;
            break;
        }
    }
    // If variable is not found, throw error
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}