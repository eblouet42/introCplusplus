#include <chrono>
#include <iostream>

int main() {
    int tablopairs[1000];
    auto start_time_point=std::chrono::high_resolution_clock::now();
    for (int i=0;i<1000;++i){
        tablopairs[i]=i*2;
    }
    auto end_time_point=std::chrono::high_resolution_clock::now();
    std::cout << "Da tableau cree en " << end_time_point-start_time_point << std::endl;
    auto sum_start_time_point= std::chrono::high_resolution_clock::now();
    int sum=0;
    for (int i=0;i<1000;++i){
        sum+=tablopairs[i];
    }
    auto sum_end_time_point = std::chrono::high_resolution_clock::now();
    std::cout << "Da somme faite en " << sum_end_time_point-sum_start_time_point << std::endl;
    std::cout << "Anyway, da somme en question: " << sum << "\n";
}