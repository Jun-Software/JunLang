/**
 * Equal function
 * By lemonorangeapple
**/
void equal(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is undeclared
    bool undeclared = true;
    // Loop through the variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable name matches
        if (variables[i].name == *(it + 1)) {
            // Check if the value is an integer
            if (isInteger(*(it + 2))) {
                // Loop through the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the variable name matches
                    if (variables[j].name == *(it + 3)) {
                        // Set the undeclared flag to false
                        undeclared = false;
                        // Set the value to true if the variable values are equal
                        variables[j].value = (variables[i].value == atoi((*(it + 2)).c_str()));
                        break;
                    }
                }
            }
            // Check if the value is a variable
            else {
                // Set the undeclared flag to true
                undeclared = true;
                // Loop through the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the variable name matches
                    if (variables[j].name == *(it + 2)) {
                        // Loop through the variables
                        for (int k = 0; k <= variableCount; k++) {
                            // Check if the variable name matches
                            if (variables[k].name == *(it + 3)) {
                                // Set the undeclared flag to false
                                undeclared = false;
                                // Set the value to true if the variable values are equal
                                variables[k].value = (variables[i].value == variables[j].value);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    // If the variable is undeclared, print an error message
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}