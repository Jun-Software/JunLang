/**
 * Equal or greater function
 * By lemonorangeapple
**/
void equal_or_greater(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is undeclared
    bool undeclared = true;
    // Loop through all the variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable name matches the first argument
        if (variables[i].name == *(it + 1)) {
            // Check if the second argument is an integer
            if (isInteger(*(it + 2))) {
                // Loop through all the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the variable name matches the third argument
                    if (variables[j].name == *(it + 3)) {
                        // Set the undeclared flag to false
                        undeclared = false;
                        // Set the value of the third argument to the value of the first argument
                        variables[j].value = (variables[i].value >= atoi((*(it + 2)).c_str()));
                        // Break out of the loop
                        break;
                    }
                }
            }
            // Check if the second argument is a variable
            else {
                // Set the undeclared flag to true
                undeclared = true;
                // Loop through all the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the variable name matches the second argument
                    if (variables[j].name == *(it + 2)) {
                        // Loop through all the variables
                        for (int k = 0; k <= variableCount; k++) {
                            // Check if the variable name matches the third argument
                            if (variables[k].name == *(it + 3)) {
                                // Set the undeclared flag to false
                                undeclared = false;
                                // Set the value of the third argument to the value of the first argument
                                variables[k].value = (variables[i].value >= variables[j].value);
                                // Break out of the loop
                                break;
                            }
                        }
                        // Break out of the inner loop
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