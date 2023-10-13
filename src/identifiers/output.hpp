/**
 * Output function
 * By lemonorangeapple
**/
void output(vector<string>::iterator it) {
    if ((*(it + 1))[0] != '"') {
        bool undeclared = true;
        for (int i = 0; i <= variableCount; i++) {
            if (variables[i].name == *(it + 1)) {
                undeclared = false;
                printf("%.3Lf", variables[i].value);
                break;
            }
        }
        if (undeclared) {
            cerr << "[Error] Variable undeclared." << endl;
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