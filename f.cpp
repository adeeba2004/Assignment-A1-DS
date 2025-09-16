#include <iostream>
#include "f.h"
#include <fstream>
#include <utility>
using namespace std;

// Reads integers from "A1input.txt" into the array
void readFile(int arr[], int& n) {
    ifstream input;
    input.open("A1input.txt"); // Open the input file
    int i = 0;
    n = 0; // Initialize size counter
    while (input >> arr[i]) {  // Read values into array
        i++;
        n++;
    }
}

// Checks if a user-provided number exists in the array
int findNum(int arr[], int& n) {
    int val;
    cout << "Enter value to check if it's in the array: ";
    cin >> val;

    // Linear search through the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << val << " found at index ";
            return i; // Returns index of found value
        }
    }
    return -1; // Not found//
}

// Modifies value at a given index, returns old and new values
Node modifyValuewithexcpt(int arr[], int& n) {
    int new_val, prev_val, idx;
    cout << "Enter the index you want to modify: ";
    cin >> idx;

    // Exception handling for invalid index
    if (idx < 0 || idx >= n) {
        throw out_of_range("Index is out of range");
    }

    // Save old value before modification
    prev_val = arr[idx];

    cout << "Enter the new value: ";
    cin >> new_val;

    arr[idx] = new_val; // Assign new value

    // Return both old and new values using Node struct
    Node k;
    k.new_val = new_val;
    k.old_val = prev_val;
    return k;
}

// Appends a new number to the end of the array
void addNumwithexcpt(int arr[], int& n) {
    int add_n;
    cout << "Enter an integer to add at the end of the array: ";
    cin >> add_n;

    // Check if array is full
    if (n >= 10000) {
        throw out_of_range("Array is full");
    }

    arr[n] = add_n; // Add at the end
    n++;            // Increase size
    cout << add_n << " added at the end of the array." << endl;
}

// Removes an element at a given index and shifts elements left
void removeNum(int arr[], int& n) {
    int idx;
    cout << "Enter index to remove: ";
    cin >> idx;

    // Exception handling for invalid index
    if (idx < 0 || idx >= n) {
        throw out_of_range("Index is out of range");
    }

    int removed = arr[idx]; // Store removed value for display

    // Shift all elements left after the removed index
    for (int i = idx; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; // Reduce size
    cout << "Removed element " << removed << " at index " << idx << endl;
}
