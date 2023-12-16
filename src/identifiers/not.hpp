/**
 * Not function
 * By lemonorangeapple
**/
void _not(vector<string>::iterator it) {
    // Check if the variable is undeclared
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        // Check if the variable is declared
        if (variables[i].name == *(it + 1)) {
            undeclared = true;
            // Check if the variable to be negated is declared
            for (int j = 0; j <= variableCount; j++) {
                if (variables[j].name == *(it + 2)) {
                    // Set the value of the variable to the opposite of the original value
                    variables[j].value = !((bool)(variables[i].value));
                    undeclared = false;
                    break;
                }
            }
        }
        break;
    }
    // If the variable is undeclared, throw an error
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}