#include "identifiers/identifiers.hpp"
void interpreter(vector<string> vec, ifstream &file) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if ((*it) == "") {
            continue;
        }
        bool unknow = true;
        for (int i = 0; i < (sizeof(identifiers) / sizeof(string)); i++) {
            if (identifiers[i] == *it) {
                unknow = false;
                break;
            }
        }
        if (!unknow) {
            if (!ifFlag.empty() && ifFlag.top() == false && (*it != identifiers[16])) {
                break;
            }
            if (!loopFlag.empty() && loopFlag.top() == false && (*it != identifiers[18])) {
                break;
            }
            if (*it == identifiers[0]) {
                output(it);
            }
            else if (*it == identifiers[1]) {
                wrap(it);
            }
            else if (*it == identifiers[2]) {
                _new(it);
            }
            else if (*it == identifiers[3]) {
                set(it);
            }
            else if (*it == identifiers[4]) {
                input(it);
            }
            else if (*it == identifiers[5]) {
                addition(it);
            }
            else if (*it == identifiers[6]) {
                subtraction(it);
            }
            else if (*it == identifiers[7]) {
                multiplication(it);
            }
            else if (*it == identifiers[8]) {
                division(it);
            }
            else if (*it == identifiers[9]) {
                equal(it);
            }
            else if (*it == identifiers[10]) {
                _greater(it);
            }
            else if (*it == identifiers[11]) {
                _less(it);
            }
            else if (*it == identifiers[12]) {
                equal_or_greater(it);
            }
            else if (*it == identifiers[13]) {
                equal_or_less(it);
            }
            else if (*it == identifiers[14]) {
                _not(it);
            }
            else if (*it == identifiers[15]) {
                _if(it);
            }
            else if (*it == identifiers[16]) {
                end_if(it);
            }
            else if (*it == identifiers[17]) {
                loop(it, file);
            }
            else if (*it == identifiers[18]) {
                end_loop(it, file);
            }
            else if (*it == identifiers[19]) {
                note(it);
            }
            break;
        }
        else {
            cerr << "[ERROR] Unknow identifier.\n";
        }
    }
}