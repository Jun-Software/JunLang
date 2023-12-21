#include <cstdlib>
#include <cstdio>
#include <string>

string execute(const char *command) {
    char buffer[1024];
    char result[1024] = {0};
    FILE *ptr;
    strcpy(result, command);
    if((ptr = popen(result, "r"))) {
        while (fgets(buffer, 1024, ptr)) {
           strcat(result, buffer);
           if (strlen(result) > 1024) {
               break;
           }
        }
        pclose(ptr);
        ptr = NULL;
    }
    return result;
}

void update() {
    string result = execute("curl https://junlang.imjcj.eu.org/VERSION").substr(41);
}
