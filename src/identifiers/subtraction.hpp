void subtraction(vector<string>::iterator it) {
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            if (isInteger(*(it + 2))) {
                variables[i].value -= atoi((*(it + 2)).c_str());
                break;
            }
            else {
                for (int j = 0; j <= variableCount; j++) {
                    if (variables[j].name == *(it + 2)) {
                        variables[i].value -= variables[j].value;
                        break;
                    }
                }
            }
        }
    }
} 