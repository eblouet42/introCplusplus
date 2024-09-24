#include <iostream>

int main() {
    int tablopairs[1000];
    tablopairs[0] = 2;
    for (int i=1; i<1000; ++i) {
        tablopairs[i] = i*2;
    }
}