/**
 * Update function
 * By lemonorangeapple
**/
#include <cstdlib>
#include <cstdio>
#include <string>

// execute external command and store result in result
string execute(const char *command) {
    char buffer[2048];
    char result[2048] = {0};
    FILE *ptr;
    strcpy(result, command);
    if ((ptr = popen(result, "r"))) {
        while (fgets(buffer, 2048, ptr)) {
            if (strlen(result) + strlen(buffer) <= 2048) {
                strcat(result, buffer);
            }
        }
        pclose(ptr);
        ptr = NULL;
    }
    return result;
}

// update function
void update() {
    // get version number from https://junlang.imjcj.eu.org/VERSION
    string result = execute("curl -s https://junlang.imjcj.eu.org/VERSION");
    result = result.substr(44);
    // compare version number with _VERSION_
    if (result != _VERSION_) {
        cout << "Warning: Please update: \"https://junlang.imjcj.eu.org\"" << endl;
    }
    return;
}
