/**
 * Subtraction function
 * By lemonorangeapple
**/
void subtraction(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is undeclared
    bool undeclared = true;
    // Loop through all variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable name matches the one in the expression
        if (variables[i].name == *(it + 1)) {
            // Check if the value is an integer
            if (isInteger(*(it + 2))) {
                // If it is, set undeclared to false and subtract the value
                undeclared = false;
                variables[i].value -= atoi((*(it + 2)).c_str());
                break;
            }
            // If it isn't, check if the value is a variable
            else {
                // If it is, set undeclared to true and loop through all variables
                undeclared = true;
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the variable name matches the one in the expression
                    if (variables[j].name == *(it + 2)) {
                        // If it does, set undeclared to false and subtract the value
                        undeclared = false;
                        variables[i].value -= variables[j].value;
                        break;
                    }
                }
            }
        }
    }
    // If the variable is undeclared, print an error
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}
