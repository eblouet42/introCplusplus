#include "Vector.h"

#include <bits/locale_facets_nonio.h>


Vector::Vector(int count, float value) {
    this->capacity=count;
    this->data=new float[this->capacity];
    this->nbelements=0;
    for(int i=0;i<this->capacity;i++) {
        this->data[i]=value;
    }
}

Vector::Vector(const Vector& other) {
    this->capacity=other.capacity;
    this->data=new float[this->capacity];
    this->nbelements=other.nbelements;
    if (other.data!=nullptr) {
        for(int i=0;i<this->nbelements;i++) {
            this->data[i]=other.data[i];
        }
    }
}

Vector::Vector(Vector&& other) noexcept {
    this->data=other.data;
    this->capacity=other.capacity;
    this->nbelements=other.nbelements;
    other.data=nullptr;
    other.capacity=0;
    other.nbelements=0;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this!=&other) {
        delete[] this->data;
        this->capacity=other.capacity;
        this->data=other.data;
        this->nbelements=other.nbelements;
        other.data=nullptr;
        other.capacity=0;
        other.nbelements=0;
    }
    return *this;
}

Vector& Vector::operator=(const Vector& other) {
    if (this!=&other) {
        this->capacity=other.capacity;
        this->data=new float[this->capacity];
        this->nbelements=other.nbelements;
        if (other.data!=nullptr) {
            for(int i=0;i<this->nbelements;i++) {
                this->data[i]=other.data[i];
            }
        }
    }
    return *this;
}


void Vector::push_back(const float& f) {
    if (this->nbelements==this->capacity) {
        reserve(2*this->capacity);
    }
    this->data[this->nbelements]=f;
    this->nbelements++;
}

void Vector::reserve(int new_cap){
    if (new_cap>this->capacity) {
        float* temp=new float[new_cap];
        for (int i=0;i<this->nbelements;i++) {
            temp[i]=this->data[i];
        }
        this->data=temp;
        this->capacity=new_cap;
        delete temp;
    }
}


