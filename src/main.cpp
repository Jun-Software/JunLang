#include "init.hpp"
#include "read.hpp"
int main(int argc, char* argv[]) {
    if (argc == 1) {
        // Output usage.
        cout << "JunLang " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename]" << endl;
        exit(0);
    }
    // Read file.
    read(argv);
    return 0;
}
