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
    for (int i = 0; i <= len; i++) {
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

void /* char* */ reverse(char s[]) {
    std::cout << "euh" << std::endl;
    int n = mylen(s);
    char reverse[n+1];
    reverse[n] = '\0';
    for (int i = 0; i < n; i++) {
        reverse[i] = s[n - i - 1];
    }
    printf("%s\n", reverse);
    //return reverse;
}

int main() {
    char s[] = "Hello World!";
    std::cout << mylen(s) << std::endl;
    std::cout << compare("kakou kakou", "kakouzz")  << std::endl;
    std::cout << compare("ohio", "amogus")  << std::endl;
    std::cout << compare("Mathis", "hugo")  << std::endl;
    std::cout << compare("Hello World!", "Hello World!") << std::endl;
    std::cout << compare(" ", "") << std::endl;
    std::cout << compare("rizz", "rizzler") << std::endl;
    std::cout << compare("Rizz", "Rizz") << std::endl;
    std::cout << palyndrome("ABBA") << std::endl;
    std::cout << palyndrome("ACAB") << std::endl;
    /*std::cout <<*/ reverse("123456789") /*<< std::endl;*/;
    std::cout << "heheheha" << std::endl;
    return 0;
}