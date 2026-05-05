
#include <iostream>
#include "Header.h"
using namespace std;

NumberArray::NumberArray(int size) { // Constructor with default parameter
	if (size <= 0) {
		this->size = maxSize;
	} else {
		this->size = size;
	}
	arr = new double[this->size](); // Initialize array

	for (int i = 0; i < this->size; i++) {
		arr[i] = 0.0; // Initialize all elements to 0.0
	}
}

NumberArray::~NumberArray() { // Destructor
	delete[] arr; // Free allocated memory
	cout << "Array memory has been freed." << endl;
}

NumberArray::NumberArray(const NumberArray& other) { // Copy constructor
	size = other.size;
	arr = new double[size];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}

}

NumberArray& NumberArray::operator=(const NumberArray& other) { // Assignment operator
	if (this == &other) {
		return *this; // Self-assignement check
	}
	delete[] arr;
	size = other.size;
	arr = new double[size];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}

void NumberArray::setNumber(int index, double value) { // Mutator to set a number at a specific index
	if (index >= 0 && index < size)  // Bounds checking to prevent out-of-bounds access
	{
		arr[index] = value;
	} 
	else 
	{
		cout << "Index out of bounds." << endl;
	}
}

double NumberArray::getNumber(int index) const { // Accessor to get a number at a specific index
	if (index >= 0 && index < size) 
	{
		return arr[index];
	} 
	else 
	{
		cout << "Index out of bounds." << endl;
		return 0.0; // Return 0 if index is out of bounds
	}
}

double NumberArray::getMinimum() const { // Function to find the minimum value in the array
	double min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

double NumberArray::getMaximum() const { // Function to find the maximum value in the array
	double max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

double NumberArray::getMean() const { // Function to calculate the average of the numbers in the array
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum / size;
}

void NumberArray::display() const { // Function to display the contents of the array
	cout << "Array contents: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}