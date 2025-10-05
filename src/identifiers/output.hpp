/**
 * Output function
 * By lemonorangeapple
**/
void output(vector<string>::iterator it, ifstream &file) {
    // Check if the next token is a variable
    string _this = *(it + 1);
    if (_this[0] != '"') {
        cout << variables[_this];
    }
    // If the next token is a string, print the string
    else {
        string result = _this;
        for (int index = 2; ; index++) {
            if (result[result.length() - 1] == '"') {
                cout << result.substr(1, result.length() - 2);
                return;
            }
            string __this = *(it + index);
            result += (" " + __this);
        }
    }
}