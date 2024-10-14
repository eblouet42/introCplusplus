#include "cstring.cpp"

#include <iostream>

void echo(int argc, char** argv){
    for (int i = 0; i < argc; ++i) {
        inverse(*(argv+i));
        std::cout << *(argv+i) << std::endl;
    }
}

int main() {
    char str1[]= "kakou kakou";
    char str2[]= "amogus";
    char str3[]= "uwu";
    char* argv[] = {str1, str2, str3};
    echo(3,argv);
}