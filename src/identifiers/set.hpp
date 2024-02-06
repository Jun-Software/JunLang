/**
 * Set function
 * By lemonorangeapple
**/
void set(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is already declared
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        // If the variable is already declared
        if (variables[i].name == *(it + 1)) {
            // If the value is an integer
            if (isInteger(*(it + 2))) {
                // Set the value to the integer
                undeclared = false;
                variables[i].value = atoi((*(it + 2)).c_str());
                break;
            }
            // If the value is not an integer
            else {
                // Check if the value is a variable
                undeclared = true;
                for (int j = 0; j <= variableCount; j++) {
                    // If the value is a variable
                    if (variables[j].name == *(it + 2)) {
                        // Set the value to the variable
                        undeclared = false;
                        variables[i].value = variables[j].value;
                        break;
                    }
                }
            }
        }
    }
    // If the variable is undeclared
    if (undeclared) {
        // Print an error message
        cerr << "[Error] Variable undeclared." << endl;
    }
}