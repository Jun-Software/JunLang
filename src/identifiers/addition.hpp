/**
 * Addition function
 * By lemonorangeapple
**/
void addition(vector<string>::iterator it) {
    // Check if the variable is already declared
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        // If the variable is already declared, add the value
        if (variables[i].name == *(it + 1)) {
            // Check if the value is an integer
            if (isInteger(*(it + 2))) {
                // Add the integer value to the variable
                variables[i].value += atoi((*(it + 2)).c_str());
                undeclared = false;
                break;
            }
            // If the value is not an integer, check if it is a variable
            else {
                undeclared = true;
                for (int j = 0; j <= variableCount; j++) {
                    // If the variable is already declared, add the value
                    if (variables[j].name == *(it + 2)) {
                        variables[i].value += variables[j].value;
                        undeclared = false;
                        break;
                    }
                }
            }
        }
    }
    // If the variable is not declared, throw an error
    if (undeclared) {
        cerr << "[ERROR] Variable undeclared. " << endl;
    }
}