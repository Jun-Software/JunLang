/**
 * Use function
 * By lemonorangeapple
**/
void _use(vector<string>::iterator it, ifstream &file) {
    string next = *(it + 1);
    if (next == "func") {
        funcUseMap[(*(it + 2))] = (int(file.tellg()));
        file.seekg(int(funcStartMap[(*(it + 2))]) - 8);
    }
    else if (next == "file") {
        string _this = *(it + 2);
        string result = _this;
        for (int index = 3; ; index++) {
            if (result[result.length() - 1] == '"') {
                fileRun.push(result.substr(1, result.length() - 2));
                return;
            }
            string __this = *(it + index);
            result += (" " + __this);
        }
    }
}