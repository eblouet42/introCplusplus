#include <iostream>
int mylen(char* s) {
    int len = 0;
    for (int i = 0; s[i] !='\0'; i++) {
        len++;
    }
    return len;
}

int compare(char* s, char* t) {
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
bool palyndrome(char* s){
    int length = mylen(s);
    for (int i=0; i<length/2; ++i) {
        if (s[i]!=s[length-i-1]) {
            return false;
        }
    }
    return true;
}

void inverse(char* s){
    int n = mylen(s);
    char temp;
    for (int i = 0; i < n / 2; i++){
        temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
}

const char* concatenate(char* s1, char* s2) {
    int len1 = mylen(s1);
    int len2 = mylen(s2);
    char* temp = new char[len1+len2+1];
    for (int i = 0; i < len1; i++) {
        temp[i] = s1[i];
    }
    for (int i = 0; i < len2; i++) {
        temp[len1+i] = s2[i];
    }
    temp[len1+len2] = '\0';
    return temp;
}

int main() {
    char* s = "Hello World!";
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
    char nombre[]="123456789";
    std::cout << "avant inversion: "<<nombre << std::endl;
    inverse(nombre);
    std::cout << "apres inversion: "<<nombre << std::endl;
    std::cout<<concatenate("kakou", "feur")<<std::endl;
    char amogus[]="amogus";
    inverse(amogus);
    std::cout<<concatenate("ohio", amogus)<<std::endl;
    return 0;
}