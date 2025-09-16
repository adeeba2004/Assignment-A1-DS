///////Adeeba Nizam

#include <iostream>
#include "f.h"
#include <fstream>
#include <utility>
#include <stdexcept>

using namespace std;

// Function to read from file 
void readFile(int arr[], int& n) {
    ifstream input;
    input.open("A1input.txt"); // Open file

    // Check if file opened successfully
    if (!input.is_open()) {
        throw runtime_error("Cannot open A1input.txt file");
    }

    n = 0; // Initialize size to 0
    int value;

    // Read values from file into array
    while (input >> value && n < 10000) {
        arr[n] = value;
        n++;
    }

    input.close();

    if (n == 0) {
        throw runtime_error("No data found in file");
    }

    cout << "Successfully read " << n << " integers from file" << endl;
}

// Function to check for an integer's presence in the array (Q1.1)
int findNum(int arr[], int& n) {
    int val;
    cout << "Enter value to check if it's in the array: ";
    cin >> val;

    // Search for value in array
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) { // Check if given int matches any int in array
            cout << val << " found at index ";
            return i; // Return the index where int is found
        }
    }

    cout << val << " not found in array" << endl;
    return -1; // When given int is not found in array
}

// Function to modify the value at a given index..//

Node modifyValuewithexcpt(int arr[], int& n) {
    int new_val, prev_val, idx;
    cout << "Enter the index for which you want to modify the value: ";
    cin >> idx;

    // Check if index is valid
    if (idx < 0 || idx >= n) {
        throw out_of_range("Index is out of range");
    }

    prev_val = arr[idx]; // Store value before modification
    cout << "Current value at index " << idx << ": " << prev_val << endl;
    cout << "Enter the new value: ";
    cin >> new_val;

    arr[idx] = new_val; // Modify the value at given index

    // Create and return Node with old and new values
    Node k;
    k.new_val = new_val;
    k.old_val = prev_val;

    return k;
}

// Function to add integer at end with exception handling
void addNumwithexcpt(int arr[], int& n) {
    int add_n;
    cout << "Enter an integer to add at the end of the array: ";
    cin >> add_n;

    // Check if array is full.
    if (n >= 10000) {
        throw out_of_range("Array is full - cannot add more elements");
    }

    arr[n] = add_n; // Add new int at the end
    n++;
    cout << add_n << " added at the end of the array" << endl;
}

// Function to remove integer at given index 
void removeNum(int arr[], int& n) {
    int idx;
    cout << "Enter index to remove: ";
    cin >> idx;

    // Check if index is valid
    if (idx < 0 || idx >= n) {
        throw out_of_range("Index is out of range");
    }

    int removed_val = arr[idx]; // Store value being removed

    // Shift elements to the left to remove the element
    for (int i = idx; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; // Decrease array size
    cout << "Removed " << removed_val << " from index " << idx << endl;

}
