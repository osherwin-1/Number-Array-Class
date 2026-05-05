#include <iostream>
#include <stdexcept>
#include "Header.h"

using namespace std;

// Constructor
template <typename T>
NumberArray<T>::NumberArray(int size) {
    if (size <= 0)
        size = maxSize;

    this->size = size;
    arr = new T[this->size]();

    for (int i = 0; i < this->size; i++)
        arr[i] = T();
}

// Destructor
template <typename T>
NumberArray<T>::~NumberArray() {
    delete[] arr;
}

// Deep Copy Constructor 
template <typename T>
NumberArray<T>::NumberArray(const NumberArray<T>& other) {
    size = other.size;
    arr = new T[size];

    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

// Deep Copy Assignment Operator
template <typename T>
NumberArray<T>& NumberArray<T>::operator=(const NumberArray<T>& other) {
    if (this == &other)
        return *this;

    delete[] arr;

    size = other.size;
    arr = new T[size];

    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];

    return *this;
}

// Mutator
template <typename T>
void NumberArray<T>::setNumber(int index, T value) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");

    arr[index] = value;
}

// Accessor
template <typename T>
T NumberArray<T>::getNumber(int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");

    return arr[index];
}

// Minimum
template <typename T>
T NumberArray<T>::getMinimum() const {
    T min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

// Maximum
template <typename T>
T NumberArray<T>::getMaximum() const {
    T max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

// Mean
template <typename T>
T NumberArray<T>::getMean() const {
    T sum = T();

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum / size;
}

// Display
template <typename T>
void NumberArray<T>::display() const {
    cout << "Array contents: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}