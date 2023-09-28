void equal_or_greater(vector<string>::iterator it) {
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            if (isInteger(*(it + 2))) {
                for (int j = 0; j <= variableCount; j++) {
                    if (variables[j].name == *(it + 3)) {
                        variables[j].value = (variables[i].value >= atoi((*(it + 2)).c_str()));
                        break;
                    }
                }
                break;
            }
            else {
                for (int j = 0; j <= variableCount; j++) {
                    if (variables[j].name == *(it + 2)) {
                        for (int k = 0; k <= variableCount; k++) {
                            if (variables[k].name == *(it + 3)) {
                                variables[k].value = (variables[i].value >= variables[j].value);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}