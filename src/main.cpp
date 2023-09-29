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
            if (str[0] != '%') {
                f << str << endl;
            }
            else if (str == "%run" || str == "%RUN" || str == "%Run") {
                char *file[] = {"", "temp.jun"};
                read(file);
                cout << endl;
            }
            else if (str == "%exit" || str == "%EXIT" || str == "%Exit") {
                f.close();
                filesystem::remove("temp.jun");
                exit(0);
            }
            else if (str == "%save" || str == "%SAVE" || str == "%Save") {
                string filename;
                cin >> filename;
                filesystem::remove(filename);
                filesystem::copy("temp.jun", filename);
            }
            else if (str == "%clear" || str == "%CLEAR" || str == "%Clear") {
                f.close();
                f = fstream();
                f.open("temp.jun", ios::out);
            }
            else {
                cout << "%run\tRun the code in buffer." << endl;
                cout << "%exit\tExit editor." << endl;
                cout << "%save <filename>\tSave file." << endl;
                cout << "%clear\tClear buffer." << endl;
                cout << "%help\tView this list." << endl;
                cout << "<code>\tPut code to buffer." << endl;
            }
        }
    }
    read(argv);
    return 0;
}