void _new(vector<string>::iterator it) {
    bool duplicate = false;
    for (int i = 0; i <= variableCount; i++) {
        if (variables[i].name == *(it + 1)) {
            duplicate = true;
            break;
        }
    }
    if (duplicate) {
        cerr << "[ERROR] Duplicate variable name.\n";
    }
    variables[variableCount++].name = *(it + 1);
}