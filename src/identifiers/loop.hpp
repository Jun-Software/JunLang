/**
 * Loop function
 * By lemonorangeapple
**/
void loop(vector<string>::iterator it, ifstream &file) {
    string next = *(it + 1);
    loopVariableName.push(next);
    if (variables[next] == 0) {
        // Push false to the loop flag vector
        loopFlag.push(false);
    }
    else {
        // Push the current line number to the loop line vector
        loopLine.push(int(file.tellg()) - 2);
        // Push true to the loop flag vector
        loopFlag.push(true);
    }
}