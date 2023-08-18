#include "init.hpp"
#include "identifiers/identifiers.hpp"
void interpreter(vector<string> vec, ifstream &file) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        bool unknow = true;
        for (int i = 0; i < (sizeof(identifiers) / sizeof(string)); i++) {
            if (identifiers[i] == *it) {
                unknow = false;
                break;
            }
        }
        if (!unknow) {
            if (!ifFlag.empty() && ifFlag.top() == false && *it != identifiers[16]) {
                break;
            }
            if (!loopFlag.empty() && loopFlag.top() == false && *it != identifiers[18]) {
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
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 3)) {
                                    variables[j].value = (variables[i].value > atoi((*(it + 2)).c_str()));
                                    undeclared = false;
                                    break;
                                }
                            }
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    undeclared = true;
                                    for (int k = 0; k <= variableCount; k++) {
                                        if (variables[k].name == *(it + 3)) {
                                            variables[k].value = (variables[i].value > variables[j].value);
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                    undeclared = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (undeclared) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[11]) {
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 3)) {
                                    variables[j].value = (variables[i].value < atoi((*(it + 2)).c_str()));
                                    undeclared = false;
                                    break;
                                }
                            }
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    undeclared = true;
                                    for (int k = 0; k <= variableCount; k++) {
                                        if (variables[k].name == *(it + 3)) {
                                            variables[k].value = (variables[i].value < variables[j].value);
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                    undeclared = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (undeclared) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[12]) {
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 3)) {
                                    variables[j].value = (variables[i].value >= atoi((*(it + 2)).c_str()));
                                    undeclared = false;
                                    break;
                                }
                            }
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    undeclared = true;
                                    for (int k = 0; k <= variableCount; k++) {
                                        if (variables[k].name == *(it + 3)) {
                                            variables[k].value = (variables[i].value >= variables[j].value);
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                    undeclared = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (undeclared) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[13]) {
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 3)) {
                                    variables[j].value = (variables[i].value <= atoi((*(it + 2)).c_str()));
                                    undeclared = false;
                                    break;
                                }
                            }
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    undeclared = true;
                                    for (int k = 0; k <= variableCount; k++) {
                                        if (variables[k].name == *(it + 3)) {
                                            variables[k].value = (variables[i].value <= variables[j].value);
                                            undeclared = false;
                                            break;
                                        }
                                    }
                                    undeclared = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (undeclared) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[14]) {
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        undeclared = true;
                        for (int j = 0; j <= variableCount; j++) {
                            if (variables[j].name == *(it + 2)) {
                                variables[j].value = !((bool)(variables[i].value));
                                undeclared = false;
                                break;
                            }
                        }
                    }
                }
                if (undeclared) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[15]) {
                bool variable = false;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (variables[i].value == 0) {
                            ifFlag.push(false);
                        }
                        else {
                            ifFlag.push(true);
                        }
                        variable = true;
                        break;
                    }
                }
                if (!variable) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[16]) {
                if (!ifFlag.empty()) {
                    ifFlag.pop();
                }
            }
            else if (*it == identifiers[17]) {
                bool variable = false;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        loopVariableName.push(string(*(it + 1)));
                        if (variables[i].value == 0) {
                            loopFlag.push(false);
                        }
                        else {
                            loopLine.push(file.tellg());
                            loopFlag.push(true);
                        }
                        variable = true;
                        break;
                    }
                }
                if (!variable) {
                    cerr << "[ERROR] Undeclared variable.\n";
                }
            }
            else if (*it == identifiers[18]) {
                if (!loopFlag.empty()) {
                    if (loopFlag.top() == true) {
                        for (int i = 0; i <= variableCount; i++) {
                            if (variables[i].name == loopVariableName.top()) {
                                if (variables[i].value == 0) {
                                    loopFlag.pop();
                                    break;
                                }
                                else {
                                    if (!loopLine.empty()) {
                                        file.seekg(loopLine.top());
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        loopFlag.pop();
                    }
                }
            }
            break;
        }
        else {
            cerr << "[ERROR] Unknow identifier.\n";
        }
    }
}