void end_loop(vector<string>::iterator it, ifstream &file) {
    if (!loopFlag.empty()) {
        if (loopFlag.top() == true) {
            for (int i = 0; i <= variableCount; i++) {
                if (variables[i].name == loopVariableName.top()) {
                    if (variables[i].value == 0) {
                        loopFlag.pop();
                        break;
                    }
                    else {
                        if (!loopLine.empty()) {
                            file.seekg(int(loopLine.top()) - 2);
                        }
                        break;
                    }
                }
            }
        }
        else {
            loopFlag.pop();
            loopLine.pop();
            loopVariableName.pop();
        }
    }
    else {
        cerr << "[Error] Much \"end-loop\"." << endl;
    }
}