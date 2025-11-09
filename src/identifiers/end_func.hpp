/**
 * End func function
 * By lemonorangeapple
**/
void end_func(vector<string>::iterator it, ifstream &file) {
    string next = funcName.top();
    funcName.pop();
    if (funcFlag.empty()) {
        file.seekg(int(funcUseMap[next]));
    }
    else {
        funcFlag.pop();
        funcEndMap[next] = (int(file.tellg()));
    }
}