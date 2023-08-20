#include "interpreter.hpp"
void read(char* argv[]) {
    string fileName = string(argv[1]);
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "[ERROR] File cannot open.\n";
        exit(0);
    }
    while (file.good()) {
        file.getline(buffer, sizeof(buffer));
        vector<string> vec(split(string(buffer), ' '));
        interpreter(vec, file);
    }
}