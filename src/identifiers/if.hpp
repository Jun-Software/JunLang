/**
 * If function
 * By lemonorangeapple
**/
void _if(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is undeclared
    bool undeclared = true;
    // Loop through the variables
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable name matches
        if (variables[i].name == *(it + 1)) {
            // Check if the variable value is 0
            if (variables[i].value == 0) {
                // Push false if the variable value is 0
                ifFlag.push(false);
            }
            else {
                // Push true if the variable value is not 0
                ifFlag.push(true);
            }
            // Break out of the loop
            undeclared = false;
            break;
        }
    }
    // If the variable is undeclared, throw an error
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}