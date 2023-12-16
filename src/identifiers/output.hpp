/**
 * Output function
 * By lemonorangeapple
**/
void output(vector<string>::iterator it) {
    // Check if the next token is a variable
    if ((*(it + 1))[0] != '"') {
        // Check if the variable is undeclared
        bool undeclared = true;
        // Check if the variable is already declared
        for (int i = 0; i <= variableCount; i++) {
            if (variables[i].name == *(it + 1)) {
                undeclared = false;
                printf("%.3Lf", variables[i].value);
                break;
            }
        }
        // If the variable is undeclared, print an error message
        if (undeclared) {
            cerr << "[Error] Variable undeclared." << endl;
        }
    }
    // If the next token is a string, print the string
    else {
        // Remove the quotation marks from the string
        string result = string(*(it + 1)).substr(1, strlen((*(it + 1)).c_str()) - 2);
        // Replace underscores with spaces
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == '_') {
                result[i] = ' ';
            }
        }
        cout << result;
    }
}