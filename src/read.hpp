/**
 * Read code function
 * By lemonorangeapple
**/
#include "interpreter.hpp"
// Read from file.
void read(char* argv[]) {
    // Open file.
    bool funcReadFlag = false;
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
        if (funcReadFlag) {
            if ((*vec.begin()) != "end-func") {
                continue;
            }
            else {
                funcReadFlag = false;
            }
        }
        if ((*vec.begin()) == "func") {
            interpreter(vec, file);
            funcReadFlag = true;
            continue;
        }
        // Interpret each line.
        interpreter(vec, file);
        if (!fileRun.empty()) {
            const char* file_top = fileRun.top().c_str();
            fileRun.pop();
            char* file_top_tmp = new char[_BUFFER_SIZE_];
            strcpy(file_top_tmp, file_top);
            char* argv_tmp[] = {"", file_top_tmp};
            read(argv_tmp);
        }
    }
}