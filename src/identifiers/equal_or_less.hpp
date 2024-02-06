/**
 * Equal or less function
 * By lemonorangeapple
**/
void equal_or_less(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is undeclared
    bool undeclared = true;
    // Loop through the variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable name matches
        if (variables[i].name == *(it + 1)) {
            // Check if the second argument is an integer
            if (isInteger(*(it + 2))) {
                // Loop through the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the third argument matches
                    if (variables[j].name == *(it + 3)) {
                        // Set the undeclared flag to false
                        undeclared = false;
                        // Set the value of the third argument to the comparison of the first and second arguments
                        variables[j].value = (variables[i].value <= atoi((*(it + 2)).c_str()));
                        // Break out of the loop
                        break;
                    }
                }
                // Break out of the loop
                break;
            }
            // If the second argument is not an integer
            else {
                // Set the undeclared flag to true
                undeclared = true;
                // Loop through the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the second argument matches
                    if (variables[j].name == *(it + 2)) {
                        // Loop through the variables
                        for (int k = 0; k <= variableCount; k++) {
                            // Check if the third argument matches
                            if (variables[k].name == *(it + 3)) {
                                // Set the undeclared flag to false
                                undeclared = false;
                                // Set the value of the third argument to the comparison of the first and second arguments
                                variables[k].value = (variables[i].value <= variables[j].value);
                                // Break out of the loop
                                break;
                            }
                        }
                        // Break out of the loop
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