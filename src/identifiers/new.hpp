/**
 * New function
 * By lemonorangeapple
**/
void _new(vector<string>::iterator it, ifstream &file) {
    // Get the name of the variable
    variables[variableCount++].name = *(it + 1);
}