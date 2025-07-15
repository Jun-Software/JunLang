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
        string result = string(_this.substr(1, strlen(_this.c_str()) - 2));
        // Replace underscores with spaces
        for (int i = 0; i <= result.size(); i++) {
            if (result[i] == '_') {
                cout << ' ';
                continue;
            }
            cout << result[i];
        }
    }
}