#include <iostream>

void printGreetings(int upperbound) {
    for (int i = 2; i <= upperbound; i+=2) {
            std::cout << i << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    int truc=upperbound;
    if (upperbound%2==0) {
        truc=upperbound-1;
    }
    for (int i=truc; i >= 1; i-=2) {
            std::cout << i << std::endl;
    }
}
int main() {
    printGreetings(10);
    printGreetings(20);
    return 0;
}
