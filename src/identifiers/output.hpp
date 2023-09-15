void output(vector<string>::iterator it) {
    if ((*(it + 1))[0] != '"') {
        bool variable = false;
        for (int i = 0; i <= variableCount; i++) {
            if (variables[i].name == *(it + 1)) {
                printf("%.3Lf", variables[i].value);
                variable = true;
                break;
            }
        }
        if (!variable) {
            cerr << "[ERROR] Undeclared variable.\n";
        }
    }
    else {
        cout << string(*(it + 1)).substr(1, strlen((*(it + 1)).c_str()) - 2);
    }
}