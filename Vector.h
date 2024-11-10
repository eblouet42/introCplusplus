#ifndef VECTOR_H
#define VECTOR_H



class Vector {
    private:
        int capacity;
        int nbelements;
        float* data;

    public:
        Vector(){capacity=42;data=new float[capacity];nbelements=0;}; // default constructor (initializing an empty vector)
        Vector(int count, float value); //constructor initializing with vector with count copies of an input value
        ~Vector(){delete[] data;} // destructor
        Vector(const Vector& other); // create a new vector by copying entries from the other vector
        Vector(Vector&& other);
        Vector& operator=(const Vector& other); // replace content of a vector by entries of another vector. It returns a reference to the modified vector, typically *this, in order to allow chaining of operators tabA = tabB = tabC;
        Vector& operator=(Vector&& other) noexcept ;
        int size() const{return nbelements;} // return number of elements
        void push_back(const float& f); // adds an element at the end of the range, reallocate memory if needed
        float& operator[](int index){return data[index];} // return the i-th element if it exists, undefined otherwise
        const float& operator[](int index) const{return data[index];} // return the i-th element if it exists, undefined otherwise
        void reserve(int new_cap); // increase the capacity of the vector to a capacity greater or equal to new_cap
};



#endif //VECTOR_H
