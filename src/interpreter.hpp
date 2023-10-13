#include "identifiers/identifiers.hpp"
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
            if (*it == identifiers[0]) {
                output(it);
            }
            // identifier: wrap
            else if (*it == identifiers[1]) {
                wrap(it);
            }
            // identifier: new
            else if (*it == identifiers[2]) {
                _new(it);
            }
            // identifier: set
            else if (*it == identifiers[3]) {
                set(it);
            }
            // identifier: input
            else if (*it == identifiers[4]) {
                input(it);
            }
            // identifier: addition
            else if (*it == identifiers[5]) {
                addition(it);
            }
            // identifier: subtraction
            else if (*it == identifiers[6]) {
                subtraction(it);
            }
            // identifier; multiplication
            else if (*it == identifiers[7]) {
                multiplication(it);
            }
            // identifier: division
            else if (*it == identifiers[8]) {
                division(it);
            }
            // identifier: equal
            else if (*it == identifiers[9]) {
                equal(it);
            }
            // identifier: greater
            else if (*it == identifiers[10]) {
                _greater(it);
            }
            // identifier: less
            else if (*it == identifiers[11]) {
                _less(it);
            }
            // identifier: equal-or-greater
            else if (*it == identifiers[12]) {
                equal_or_greater(it);
            }
            // identifier: equal-or-less
            else if (*it == identifiers[13]) {
                equal_or_less(it);
            }
            // identifier: not
            else if (*it == identifiers[14]) {
                _not(it);
            }
            // identifier: if
            else if (*it == identifiers[15]) {
                _if(it);
            }
            // identifier: end-if
            else if (*it == identifiers[16]) {
                end_if(it);
            }
            // identifier: loop
            else if (*it == identifiers[17]) {
                loop(it, file);
            }
            // identifier: end-loop
            else if (*it == identifiers[18]) {
                end_loop(it, file);
            }
            // identifier: note
            else if (*it == identifiers[19]) {
                note(it);
            }
            break;
        }
        else {
            cerr << "[Error] Unknown identifiers" << endl;
        }
    }
}
