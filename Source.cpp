#include <iostream>
#include <random>
#include "Header.h"

using namespace std;

int main() { // Main function to demonstrate the NumberArray class
    // Default constructor
    NumberArray arr1;

    cout << "Default array:\n";
    arr1.display();

    // Parameterized constructor
    NumberArray arr2(5);

    // Random number setup
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(1.0, 100.0);


    // Statistics for known array
	cout << "\nKnown array:\n";
	arr2.setNumber(0, 2);
	arr2.setNumber(1, 4);
	arr2.setNumber(2, 6);
	arr2.setNumber(3, 8);
	arr2.setNumber(4, 10);
	arr2.display();
    cout << "\nMin: " << arr2.getMinimum() << endl;
    cout << "Max: " << arr2.getMaximum() << endl;
    cout << "Average: " << arr2.getMean() << endl;
    
    // Fill array with random numbers
    for (int i = 0; i < 5; i++) {
        arr2.setNumber(i, dist(gen));
    }

    cout << "\nRandom-filled array:\n";
    arr2.display();

    // Statistics
    cout << "\nMin: " << arr2.getMinimum() << endl;
    cout << "Max: " << arr2.getMaximum() << endl;
    cout << "Average: " << arr2.getMean() << endl;

    // Valid Index Tests
    cout << "\nValid Index Tests:\n";

    NumberArray testArr(5);

    // Store values at first, middle, and last index
    testArr.setNumber(0, 10.5);   // first index
    testArr.setNumber(2, 25.75);  // middle index
    testArr.setNumber(4, 99.9);   // last index

    // Retrieve and display values
    cout << "First index (0): " << testArr.getNumber(0) << endl;
    cout << "Middle index (2): " << testArr.getNumber(2) << endl;
    cout << "Last index (4): " << testArr.getNumber(4) << endl;

    // Confirm values match expected
    cout << "\nVerification:\n";
    cout << "Expected 10.5: " << testArr.getNumber(0) << endl;
    cout << "Expected 25.75: " << testArr.getNumber(2) << endl;
    cout << "Expected 99.9: " << testArr.getNumber(4) << endl;
    
    // Out-of-bounds tests
    cout << "\nOut-of-bounds tests (i = -10, i = array size):" << endl;
    arr2.setNumber(-10, 5);
    cout << arr2.getNumber(-10) << endl;
    arr2.setNumber(5, 5);
    cout << arr2.getNumber(5) << endl;

    cout << "\nEdge Case Tests:\n";

    // Test array size of 1 (Edge case)
    NumberArray edgeArr(1);

    edgeArr.setNumber(0, -3.5);

    cout << "\nSingle-element array:\n";
    edgeArr.display();

    cout << "Min: " << edgeArr.getMinimum() << endl;
    cout << "Max: " << edgeArr.getMaximum() << endl;
    cout << "Average: " << edgeArr.getMean() << endl;

    cout << "Value at index 0: " << edgeArr.getNumber(0) << endl;

    edgeArr.setNumber(0, 0.0);
    cout << "\nUpdated to 0.0:\n";
    edgeArr.display();

    cout << "Min: " << edgeArr.getMinimum() << endl;
    cout << "Max: " << edgeArr.getMaximum() << endl;
    cout << "Average: " << edgeArr.getMean() << endl;

    edgeArr.setNumber(0, 7.25);
    cout << "\nUpdated to 7.25:\n";
    edgeArr.display();

    cout << "Min: " << edgeArr.getMinimum() << endl;
    cout << "Max: " << edgeArr.getMaximum() << endl;
    cout << "Average: " << edgeArr.getMean() << endl;
    return 0;
}