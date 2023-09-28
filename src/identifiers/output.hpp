void output(vector<string>::iterator it) {
    if ((*(it + 1))[0] != '"') {
        for (int i = 0; i <= variableCount; i++) {
            if (variables[i].name == *(it + 1)) {
                printf("%.3Lf", variables[i].value);
                break;
            }
        }
    }
    else {
        string result = string(*(it + 1)).substr(1, strlen((*(it + 1)).c_str()) - 2);
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == '_') {
                result[i] = ' ';
            }
        }
        cout << result;
    }
}