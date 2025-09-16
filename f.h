#include<iostream>
using namespace std;
#include<utility>

// Struct to store old and new values for modify function
struct Node {
    int old_val, new_val;
};

// Function declarations
void readFile(int arr[], int& n);// Reads numbers from file into array
int findNum(int arr[], int& n);// Finds number in array, returns index or -1
Node modifyValuewithexcpt(int arr[], int& n); // Modifies value at index, returns old & new values
void addNumwithexcpt(int arr[], int& n);  // Adds new number at the end (with exception handling)
void removeNum(int arr[], int& n);   // Removes number at given index (shifts left)

