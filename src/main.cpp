#include "init.hpp"
#include "read.hpp"
int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "JunLang " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename]" << endl;
        string str;
        fstream f;
        f.open("temp.jun", ios::out);
        while (cout << ">>", getline(cin, str)) {
            if (str == "%run" || str == "%RUN" || str == "%Run") {
                char *file[] = {"", "temp.jun"};
                read(file);
                cout << endl;
            }
            else if (str == "%exit" || str == "%EXIT" || str == "%Exit") {
                f.close();
                filesystem::remove("temp.jun");
                exit(0);
            }
            else if (str == "%clear" || str == "%CLEAR" || str == "%Clear") {
                f.close();
                f = fstream();
                f.open("temp.jun", ios::out);
            }
            else if (str == "%help" || str == "%HELP" || str == "%Help") {
                cout << "%run\tRun the code in buffer." << endl;
                cout << "%exit\tExit editor." << endl;
                cout << "%clear\tClear buffer." << endl;
                cout << "%help\tView this list." << endl;
                cout << "Code\tPut code to buffer." << endl;
            }
            else {
                f << str << endl;
            }
        }
    }
    read(argv);
    return 0;
}