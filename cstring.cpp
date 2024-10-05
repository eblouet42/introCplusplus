#include <iostream>
int mylen(char s[]) {
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int main() {
    char s[] = "Hello World!";
    std::cout << mylen(s) << std::endl;
    return 0;
}
