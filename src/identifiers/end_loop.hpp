/**
 * End loop function
 * By lemonorangeapple
**/
void end_loop(vector<string>::iterator it, ifstream &file) {
    // Check if there is loop flag
    if (!loopFlag.empty()) {
        // Check if loop flag is true
        if (loopFlag.top() == true) {
            // Check if loop variable name is correct
            for (int i = 0; i <= variableCount; i++) {
                if (variables[i].name == loopVariableName.top()) {
                    // Check if loop variable value is 0
                    if (variables[i].value == 0) {
                        // Pop loop flag
                        loopFlag.pop();
                        break;
                    }
                    else {
                        // Check if loop line is empty
                        if (!loopLine.empty()) {
                            // Seekg to loop line
                            file.seekg(int(loopLine.top()) - 2);
                        }
                        break;
                    }
                }
            }
        }
        else {
            // Pop loop flag
            loopFlag.pop();
            // Pop loop line
            loopLine.pop();
            // Pop loop variable name
            loopVariableName.pop();
        }
    }
    else {
        // Print error message
        cerr << "[Error] Much \"end-loop\"." << endl;
    }
}