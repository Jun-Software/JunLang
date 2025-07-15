/**
 * Not function
 * By lemonorangeapple
**/
void _not(vector<string>::iterator it, ifstream &file) {
    string next = *(it + 1);
    variables[next] = !(bool(variables[next]));
}