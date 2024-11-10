#include "templaSTL.h"

#include <iostream>


    int main() {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Span span(arr, 10);
        std::cout<<"1-10 Span: ";
        span.print();
        std::cout<<"Index 2: "<<span[2]<<std::endl;
        Span subspan=span.subspan(3, 8);
        std::cout<<"Subspan (Index 3-8): ";
        subspan.print();
        for (int i=0; i<10; i++) {if(span[i]%2==0){span[i]=span[i]*2-1;}}
        std::cout<<"Span modifié: ";
        span.print();
        return 0;
    }
