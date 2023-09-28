mkdir dist
sudo apt install g++
g++ ./src/main.cpp -std=c++20 -static -w -o ./dist/JunLang.out
g++ ./src/terminal.cpp -std=c++20 -static -w -o ./dist/Terminal.out
sudo apt install mingw-w64
x86_64-w64-mingw32-g++ ./src/main.cpp -std=c++20 -static -w -o ./dist/JunLang.exe
x86_64-w64-mingw32-g++ ./src/terminal.cpp -std=c++20 -static -w -o ./dist/Terminal.exe