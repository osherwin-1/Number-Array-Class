#include <iostream>
#include <stdexcept>
#include "NumberArray.h"
#include "Number Array Class.cpp"

using namespace std;

int main() {
	// Template Instantiation
	cout << "Template Instantiation Tests" << endl;
	NumberArray<int> intArray(5); // Integer array

	NumberArray<double> doubleArray(5); // Double array
	
	for (int i = 0; i < 5; i++) {
		doubleArray.setNumber(i, i + 0.5);
		intArray.setNumber(i, i + 10);
	}
	cout << "Integer Array: "; 
	intArray.display();
	cout << "Double Array: ";
	doubleArray.display();

	// Exception
	cout << "\nException Handling Tests" << endl;
	try {
		cout << "Valid access: " << intArray.getNumber(2) << endl;
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}
	try {
		cout << "Invalid access (too large): ";
		cout << intArray.getNumber(123456) << endl;
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}
	try {
		cout << "Invalid access (negative): ";
		cout << intArray.getNumber(-1) << endl;
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}
	// Copy Constructor
	cout << "\nCopy Constructor Tests" << endl;
	NumberArray<int> a(5);
	for (int i = 0; i < 5; i++)
		a.setNumber(i, i + 1);

	NumberArray<int> b(a);

	cout << "Original a: "; a.display();
	cout << "Copy b:     "; b.display();

	a.setNumber(0, 80);
	a.setNumber(1, 90);

	cout << "After modifying a:\n";
	cout << "a: "; a.display();
	cout << "b: "; b.display();

	// Assignment Operator
	cout << "\nAssignment Operator Tests" << endl;
	NumberArray<int> c(5);
	NumberArray<int> d(5);

	for (int i = 0; i < 5; i++)
		c.setNumber(i, i + 3);

	d = c;

	cout << "c: "; c.display();
	cout << "d: "; d.display();

	c.setNumber(1, 1000);
	c.setNumber(4, 1001);

	cout << "After modifying c:\n";
	cout << "c: "; c.display();
	cout << "d: "; d.display();

	// Self-Assignment
	cout << "\nSelf-Assignment Test" << endl;
	d = d;
	d.display();
	return 0;
}
