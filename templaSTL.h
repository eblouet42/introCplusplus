//
// Created by evan on 22/10/2024.
//

#ifndef TEMPLASTL_H
#define TEMPLASTL_H
#include <iostream>


class templaSTL {
};

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
class Span {
private:
    T* data;
    int taille;

public:
    Span(T* ptr, int size){data=ptr,taille=size;}
    ~Span(){delete[] data;}
    T& operator[](int i){return data[i];}
    int length(){return taille;}
    Span subspan(int start, int end){return Span(data+start, end-start+1);}
    void print() {
        for (int i = 0; i < length(); i++){std::cout << data[i] << " ";}
        std::cout << std::endl;
    }
};



#endif //TEMPLASTL_H
