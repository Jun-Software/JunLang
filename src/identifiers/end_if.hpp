/**
 * End if function
 * By lemonorangeapple
**/
void end_if(vector<string>::iterator it) {
    if (!ifFlag.empty()) {
        ifFlag.pop();
    }
    else {
        cerr << "[Error] Much \"end-if\"." << endl;
    }
}