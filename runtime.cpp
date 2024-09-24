#include <chrono>
#include <iostream>

int main() {
    int tablopairs[1000];
    auto start_time_point=std::chrono::high_resolution_clock::now();
    tablopairs[0] = 2;
    for (int i=1; i<1000; ++i) {
        tablopairs[i] = i*2;
    }
    auto end_time_point = std::chrono::high_resolution_clock::now();
    std::cout << "Da tableau créé en " << end_time_point-start_time_point << std::endl;
}