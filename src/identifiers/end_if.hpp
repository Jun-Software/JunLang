void end_if(vector<string>::iterator it) {
    if (!ifFlag.empty()) {
        ifFlag.pop();
    }
}