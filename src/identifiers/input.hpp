/**
 * Input function
 * By lemonorangeapple
**/
void input(vector<string>::iterator it, ifstream &file) {
    long double temp;
    cin >> temp;
    variables[*(it + 1)].value = temp;
}