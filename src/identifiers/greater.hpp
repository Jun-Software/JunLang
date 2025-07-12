/**
 * Greater function
 * By lemonorangeapple
**/
void _greater(vector<string>::iterator it, ifstream &file) {
    // Check if the first variable is undeclared
    bool undeclared = true;
    // Loop through all variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the first variable is equal to the name of the variable
        if (variables[i].name == *(it + 1)) {
            // Check if the second variable is an integer
            if (isInteger(*(it + 2))) {
                // Loop through all variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the second variable is equal to the name of the variable
                    if (variables[j].name == *(it + 3)) {
                        // Set undeclared to false
                        undeclared = false;
                        // Set the value of the second variable to the greater of the first and the second
                        variables[j].value = (variables[i].value > atoi((*(it + 2)).c_str()));
                        // Break out of the loop
                        break;
                    }
                }
                // Break out of the loop
                break;
            }
            // If the second variable is not an integer
            else {
                // Set undeclared to true
                undeclared = true;
                // Loop through all variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the second variable is equal to the name of the variable
                    if (variables[j].name == *(it + 2)) {
                        // Loop through all variables
                        for (int k = 0; k <= variableCount; k++) {
                            // Check if the third variable is equal to the name of the variable
                            if (variables[k].name == *(it + 3)) {
                                // Set undeclared to false
                                undeclared = false;
                                // Set the value of the third variable to the greater of the first and the third
                                variables[k].value = (variables[i].value > variables[j].value);
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
    // If the first variable is undeclared
    if (undeclared) {
        // Print an error message
        cerr << "[Error] Variable undeclared." << endl;
    }
}