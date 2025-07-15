/**
 * Interpreter function of the program
 * By lemonorangeapple
**/
void interpreter(vector<string> vec, ifstream &file) {
    // Read identifiers.
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if ((*it) == "") {
            continue;
        }
        // identifier: end-if.
        if (!ifFlag.empty() && ifFlag.top() == false && (*it != "end_if")) {
            continue;
        }
        // identifier: end-loop
        if (!loopFlag.empty() && loopFlag.top() == false && (*it != "end_loop")) {
            continue;
        }
        map <string, void (*)(vector<string>::iterator, ifstream &)>::iterator it2 = identifiers.find(*it);
        if (it2 != identifiers.end()) {
            it2 -> second(it, file);
            return;
        }
        else {
            cerr << "[Error] Unknown identifier: " << *it << endl;
        }
    }
}