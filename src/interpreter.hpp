/**
 * Interpreter function of the program
 * By lemonorangeapple
**/
#include "identifiers/identifiers.hpp"
void add_function(vector<string>::iterator it, ifstream &file, int num_identifier, function<void(vector<string>::iterator, ifstream &file)> the_function) {
    if (*it == identifiers[num_identifier]) {
        (the_function)(it, file);
    }
}
void interpreter(vector<string> vec, ifstream &file) {
    // Read identifiers.
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if ((*it) == "") {
            continue;
        }
        bool unknown = true;
        for (int i = 0; i < (sizeof(identifiers) / sizeof(string)); i++) {
            if (identifiers[i] == *it) {
                unknown = false;
                break;
            }
        }
        if (!unknown) {
            // identifier: end-if.
            if (!ifFlag.empty() && ifFlag.top() == false && (*it != identifiers[16])) {
                break;
            }
            // identifier: end-loop
            if (!loopFlag.empty() && loopFlag.top() == false && (*it != identifiers[18])) {
                break;
            }
            // identifier: output
            add_function(it, file, 0, output);
            // identifier: wrap
            add_function(it, file, 1, wrap);
            // identifier: new
            add_function(it, file, 2, _new);
            // identifier: set
            add_function(it, file, 3, set);
            // identifier: input
            add_function(it, file, 4, input);
            // identifier: addition
            add_function(it, file, 5, addition);
            // identifier: subtraction
            add_function(it, file, 6, subtraction);
            // identifier; multiplication
            add_function(it, file, 7, multiplication);
            // identifier: division
            add_function(it, file, 8, division);
            // identifier: equal
            add_function(it, file, 9, _equal);
            // identifier: greater
            add_function(it, file, 10, _greater);
            // identifier: less
            add_function(it, file, 11, _less);
            // identifier: equal-or-greater
            add_function(it, file, 12, equal_or_greater);
            // identifier: equal-or-less
            add_function(it, file, 13, equal_or_less);
            // identifier: not
            add_function(it, file, 14, _not);
            // identifier: if
            add_function(it, file, 15, _if);
            // identifier: end-if
            add_function(it, file, 16, end_if);
            // identifier: loop
            add_function(it, file, 17, loop);
            // identifier: end-loop
            add_function(it, file, 18, end_loop);
            // identifier: note
            add_function(it, file, 19, note);
            break;
        }
        else {
            cerr << "[Error] Unknown identifiers" << endl;
        }
    }
}