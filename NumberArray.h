#pragma once
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

using namespace std;

template <typename T>
class NumberArray {
private:
    int size;
    T* arr;
    static const int maxSize = 10;
public:
    // Constructor
    NumberArray(int size = maxSize);

    // Destructor
    ~NumberArray();

    // Copy constructor (deep copy)
    NumberArray(const NumberArray<T>& other);

    // Assignment operator (deep copy)
    NumberArray<T>& operator=(const NumberArray<T>& other);

    // Mutator
    void setNumber(int index, T value);

    // Accessor
    T getNumber(int index) const;

    // Stats
    T getMinimum() const;
    T getMaximum() const;
    T getMean() const;

    // Display
    void display() const;
};
#endif