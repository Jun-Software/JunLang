/**
 * Equal or less function
 * By lemonorangeapple
**/
void equal_or_less(vector<string>::iterator it, ifstream &file) {
    string a = *(it + 1), b = *(it + 2), c = *(it + 3);
    if (isInteger(b)) {
        variables[c] = (variables[a] <= atoi(b.c_str()));
    }
    else if (isInteger(a)){
        variables[c] = (atoi(a.c_str()) <= variables[b]);
    }
    else {
        variables[c] = (variables[a] <= variables[b]);
    }
}