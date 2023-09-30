#include "init.hpp"
#include "read.hpp"
int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "JunLang " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename]" << endl;
        string str;
        fstream f;
        string temp_filename = to_string(time(nullptr)) + ".jun";
        f.open(temp_filename, ios::out);
        while (cout << ">>", getline(cin, str)) {
            if (str[0] != '%') {
                f << str << endl;
            }
            else if (str.find("%run") != str.npos || str.find("%RUN") != str.npos || str.find("%Run") != str.npos) {
                char *file[] = {"", temp_filename.data()};
                read(file);
                cout << endl;
            }
            else if (str.find("%exit") != str.npos || str.find("%EXIT") != str.npos || str.find("%Exit") != str.npos) {
                f.close();
                filesystem::remove(temp_filename);
                exit(0);
            }
            else if (str.find("%clear") != str.npos || str.find("%CLEAR") != str.npos || str.find("%Clear") != str.npos) {
                f.close();
                f = fstream();
                f.open(temp_filename, ios::out);
            }
            else {
                cout << "%run\tRun the code in buffer." << endl;
                cout << "%exit\tExit editor." << endl;
                cout << "%clear\tClear buffer." << endl;
                cout << "%help\tView this list." << endl;
                cout << "<code>\tPut code to buffer." << endl;
            }
        }
    }
    read(argv);
    return 0;
}