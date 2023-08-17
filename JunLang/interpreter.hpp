#include "init.hpp"
#include "identifers/identifers.hpp"
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
            if (*it == identifiers[0]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                output(it);
                break;
            }
            else if (*it == identifiers[1]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                wrap(it);
                break;
            }
            else if (*it == identifiers[2]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                _new(it);
                break;
            }
            else if (*it == identifiers[3]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                set(it);
                break;
            }
            else if (*it == identifiers[4]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                input(it);
                break;
            }
            else if (*it == identifiers[5]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            variables[i].value += atoi((*(it + 2)).c_str());
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    variables[i].value += variables[j].value;
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
                break;
            }
            else if (*it == identifiers[6]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            variables[i].value -= atoi((*(it + 2)).c_str());
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    variables[i].value -= variables[j].value;
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
                break;
            }
            else if (*it == identifiers[7]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            variables[i].value *= atoi((*(it + 2)).c_str());
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    variables[i].value *= variables[j].value;
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
                break;
            }
            else if (*it == identifiers[8]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            variables[i].value /= atoi((*(it + 2)).c_str());
                            undeclared = false;
                            break;
                        }
                        else {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 2)) {
                                    variables[i].value /= variables[j].value;
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
                break;
            }
            else if (*it == identifiers[9]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                bool undeclared = true;
                for (int i = 0; i <= variableCount; i++) {
                    if (variables[i].name == *(it + 1)) {
                        if (isInteger(*(it + 2))) {
                            undeclared = true;
                            for (int j = 0; j <= variableCount; j++) {
                                if (variables[j].name == *(it + 3)) {
                                    variables[j].value = (variables[i].value == atoi((*(it + 2)).c_str()));
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
                                            variables[k].value = (variables[i].value == variables[j].value);
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
                break;
            }
            else if (*it == identifiers[10]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[11]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[12]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[13]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[14]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[15]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[16]) {
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
                if (!ifFlag.empty()) {
                    ifFlag.pop();
                }
                break;
            }
            else if (*it == identifiers[17]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
                if (!loopFlag.empty() && loopFlag.top() == false) {
                    break;
                }
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
                break;
            }
            else if (*it == identifiers[18]) {
                if (!ifFlag.empty() && ifFlag.top() == false) {
                    break;
                }
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
                break;
            }
        }
        else {
            cerr << "[ERROR] Unknow identifier.\n";
        }
    }
}