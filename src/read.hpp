#include "interpreter.hpp"
// Read from file.
void read(char* argv[]) {
    // Open file.
    string fileName = string(argv[1]);
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "[ERROR] File cannot open.\n";
        exit(0);
    }
    // Read file.
    while (file.good()) {
        file.getline(buffer, sizeof(buffer));
        // Split each line.
        vector<string> vec(split(string(buffer), ' '));
        // Interpret each line.
        interpreter(vec, file);
    }
}