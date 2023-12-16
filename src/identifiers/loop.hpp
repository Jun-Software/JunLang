/**
 * Loop function
 * By lemonorangeapple
**/
void loop(vector<string>::iterator it, ifstream &file) {
    // Check if the variable is declared
    bool undeclared = true;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            undeclared = false;
            // Push the variable name to the loop variable name vector
            loopVariableName.push(string(*(it + 1)));
            // Check if the variable is assigned
            if (variables[i].value == 0) {
                // Push false to the loop flag vector
                loopFlag.push(false);
            }
            else {
                // Push the current line number to the loop line vector
                loopLine.push(int(file.tellg()) - 2);
                // Push true to the loop flag vector
                loopFlag.push(true);
            }
            break;
        }
    }
    // If the variable is undeclared, throw an error
    if (undeclared) {
        cerr << "[Error] Variable undeclared." << endl;
    }
}