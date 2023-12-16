/**
 * Division function
 * By lemonorangeapple
**/
void division(vector<string>::iterator it) {
    // Check if the variable is undeclared
    bool undeclared = true;
    // Loop through the variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable name matches the one in the expression
        if (variables[i].name == *(it + 1)) {
            // Check if the value is an integer
            if (isInteger(*(it + 2))) {
                // Divide the value by the integer
                variables[i].value /= atoi((*(it + 2)).c_str());
                // Set undeclared to false
                undeclared = false;
                // Break out of the loop
                break;
            }
            // If the value is not an integer
            else {
                // Set undeclared to true
                undeclared = true;
                // Loop through the variables
                for (int j = 0; j <= variableCount; j++) {
                    // Check if the variable name matches the one in the expression
                    if (variables[j].name == *(it + 2)) {
                        // Divide the value by the value of the other variable
                        variables[i].value /= variables[j].value;
                        // Set undeclared to false
                        undeclared = false;
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
        cerr << "[ERROR] Variable undeclared. " << endl;
    }
}