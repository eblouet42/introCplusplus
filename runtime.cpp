#include <chrono>
#include <iostream>

void compare_runtime(int capacity) {
    uint64_t tablopairs[capacity];
    std::cout << "Pour un tableau de "<< capacity<<" elements, en C++..." << std::endl ;
    auto start_time_point=std::chrono::high_resolution_clock::now();
    for (int i=0;i<capacity;++i){
        tablopairs[i]=i*2;
    }
    auto end_time_point=std::chrono::high_resolution_clock::now();
    std::cout << "Da tableau cree en " << std::chrono::duration_cast<std::chrono::microseconds>(end_time_point-start_time_point) << std::endl;
    auto sum_start_time_point= std::chrono::high_resolution_clock::now();
    uint64_t sum=0;
    for (int i=0;i<capacity;++i){
        sum+=tablopairs[i];
    }
    auto sum_end_time_point = std::chrono::high_resolution_clock::now();
    std::cout << "Da somme faite en " << std::chrono::duration_cast<std::chrono::microseconds>(sum_end_time_point-sum_start_time_point) << std::endl;
    std::cout << "Anyway, da somme en question: " << sum << "\n";
}

int main() {
    compare_runtime(1000);
    compare_runtime(10000);
    compare_runtime(100000);
    compare_runtime(1000000);
    return 0;
}

//C'est bien plus rapide sur C++ que sur Python,
//et plus de problème d'overflow avec uint64_t
