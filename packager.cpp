#include <iostream>
#include <filesystem>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "Usage: " << argv[0] << " [filename]";
        return 0;
    }
    string filename = argv[1];
    while (filename.find('.') != string::npos) {
        filename.replace(filename.find('.'), 1, "_");
    }
    filesystem::create_directory(filename);
    filesystem::copy(argv[1], filename + "/" + argv[1]);
    fstream run_bat;
    run_bat.open(filename + "/run.bat", ios::out);
    run_bat << "@echo off" << endl;
    run_bat << "JunLang.exe " << argv[1] << endl;
    run_bat.close();
    fstream run_sh;
    run_sh.open(filename + "/run.sh", ios::out);
    run_sh << "chmod +x JunLang.out" << endl;
    run_sh << "./JunLang.out " << argv[1] << endl;
    run_sh.close();
    return 0;
}