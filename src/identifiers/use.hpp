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
}