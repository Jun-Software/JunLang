/**
 * Set function
 * By lemonorangeapple
**/
void set(vector<string>::iterator it, ifstream &file) {
    string next = *(it + 2);
    string _this = *(it + 1);
    if (isInteger(next)) {
        variables[_this] = atoi((next).c_str());
    }
    else {
        variables[_this] = variables[next];
    }
}