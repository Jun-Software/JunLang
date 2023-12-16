/**
 * End if function
 * By lemonorangeapple
**/
void end_if(vector<string>::iterator it) {
    // Check if the ifFlag is empty
    if (!ifFlag.empty()) {
        // Pop the last element of ifFlag
        ifFlag.pop();
    }
    else {
        // Print an error message if ifFlag is empty
        cerr << "[Error] Much \"end-if\"." << endl;
    }
}