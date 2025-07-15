/**
 * Less function
 * By lemonorangeapple
**/
void _less(vector<string>::iterator it, ifstream &file) {
    string a = *(it + 1), b = *(it + 2), c = *(it + 3);
    if (isInteger(b)) {
        variables[c] = (variables[a] < b);
    }
    else if (isInteger(a)){
        variables[c] = (a < variables[b]);
    }
    else {
        variables[c] = (variables[a] < variables[b]);
    }
}