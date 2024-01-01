/**
 * Update function
 * By lemonorangeapple
**/
#include <cstdlib>
#include <cstdio>
#include <string>

// execute external command and store result in result
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

// update function
void update() {
  // get version number from https://junlang.imjcj.eu.org/VERSION
  string result = execute("curl -s https://junlang.imjcj.eu.org/VERSION").substr(44);
  // compare version number with _VERSION_
  if (result != _VERSION_ + '\n') {
      cout << "Warning: Please update: \"https://junlang.imjcj.eu.org\"" << endl;
  }
  return;
}
