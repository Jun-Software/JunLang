void loop(vector<string>::iterator it, ifstream &file) {
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            loopVariableName.push(string(*(it + 1)));
            if (variables[i].value == 0) {
                loopFlag.push(false);
            }
            else {
                loopLine.push(int(file.tellg()) - 2);
                loopFlag.push(true);
            }
            break;
        }
    }
}