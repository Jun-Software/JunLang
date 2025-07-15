/**
 * End loop function
 * By lemonorangeapple
**/
void end_loop(vector<string>::iterator it, ifstream &file) {
    // Check if there is loop flag
    if (!loopFlag.empty()) {
        // Check if loop flag is true
        if (loopFlag.top() == true) {
            if (variables[loopVariableName.top()] == 0) {
                // Pop loop flag
                loopFlag.pop();
            }
            else if (!loopLine.empty()) {
                // Seekg to loop line
                file.seekg(int(loopLine.top()) - 3);
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