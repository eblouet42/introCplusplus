#include <iostream>
int mylen(char s[]) {
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int compare(char s[], char t[]) {
    int len = mylen(t);
    for (int i = 0; i < len; i++) {
        if (s[i] < t[i]) {
            return -1;
        } if (s[i] > t[i]) {
            return 1;
        }
    }
    return 0;
}
bool palyndrome(char s[]){
    int length = mylen(s);
    for (int i=0; i<length/2; ++i) {
        if (s[i]!=s[length-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[] = "Hello World!";
    std::cout << mylen(s) << std::endl;
    std::cout << compare("kakou kakou", "kakouzz")  << std::endl;
    std::cout << compare("ohio", "amogus")  << std::endl;
    std::cout << compare("Mathis", "hugo")  << std::endl;
    std::cout << compare("Hello World!", "Hello World!") << std::endl;
    std::cout << compare(" ", "") << std::endl;
    return 0;
}