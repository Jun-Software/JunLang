/**
 * Func function
 * By lemonorangeapple
**/
void func(vector<string>::iterator it, ifstream &file) {
    string next = *(it + 1);
    funcStartMap[next] = (int(file.tellg()));
    funcFlag.push(true);
}