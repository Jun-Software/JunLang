/**
 * Entry function of the program
 * By lemonorangeapple
**/
#include "init.hpp"
map <string, void (*)(vector<string>::iterator, ifstream &)> identifiers;
#include "identifiers/identifiers.hpp"
#include "read.hpp"
#include "update.hpp"
void load() {
    identifiers["output"] = output;
    identifiers["wrap"] = wrap;
    identifiers["new"] = _new;
    identifiers["set"] = set;
    identifiers["input"] = input;
    identifiers["addition"] = addition;
    identifiers["subtraction"] = subtraction;
    identifiers["multiplication"] = multiplication;
    identifiers["division"] = division;
    identifiers["equal"] = equal;
    identifiers["greater"] = _greater;
    identifiers["less"] = _less;
    identifiers["equal_or_greater"] = equal_or_greater;
    identifiers["equal_or_less"] = equal_or_less;
    identifiers["not"] = _not;
    identifiers["if"] = _if;
    identifiers["end_if"] = end_if;
    identifiers["loop"] = loop;
    identifiers["end_loop"] = end_loop;
    identifiers["note"] = note;
}
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
    load();
    // Read file.
    read(argv);
    return 0;
}