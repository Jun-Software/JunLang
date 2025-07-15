/**
 * If function
 * By lemonorangeapple
**/
void _if(vector<string>::iterator it, ifstream &file) {
    if (variables[*(it + 1)].value == 0) {
        // Push false if the variable value is 0
        ifFlag.push(false);
    }
    else {
        // Push true if the variable value is not 0
        ifFlag.push(true);
    }
}