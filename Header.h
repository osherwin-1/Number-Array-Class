#pragma once
#define HEADER_H
#include <iostream>

class NumberArray {
private:
	int size;
	double* arr;
	static const int maxSize = 10;

public:
	
	NumberArray(int size = maxSize); // Constructor with default parameter
	~NumberArray(); // Destructor
	NumberArray(const NumberArray& other); // Copy constructor

	NumberArray& operator=(const NumberArray& other); // Assignment Operator

	void setNumber(int index, double value); // Mutator to set a number at a specific index

	double getNumber(int index) const; // Accessor to get a number at a specific index

	double getMinimum() const; // Function to find the minimum value in the array
	double getMaximum() const; // Function to find the maximum value in the array
	double getMean() const; // Function to calculate the average of the numbers in the array

	void display() const; // Function to display the contents of the array
};