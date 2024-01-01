/**
 * Entry function of the program
 * By lemonorangeapple
**/
#include "init.hpp"
#include "read.hpp"
#include "update.hpp"
int main(int argc, char* argv[]) {
    // Check if there is a filename.
    if (argc == 1) {
        // Output usage.
        cout << "JunLang " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename]" << endl;
        // Check update.
        update();
        exit(0);
    }
    // Read file.
    read(argv);
    return 0;
}