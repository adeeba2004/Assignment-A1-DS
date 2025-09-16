///Adeeba Nizam

#ifndef F_H
#define F_H

#include <iostream>
#include <utility>

 // Struct to store old and new values for modify function
struct Node {
    int old_val;
    int new_val;
};

// Function declarations

/**
Reads integers from A1input.txt into array
 arr Array to store data
 n Reference to size 
 */
void readFile(int arr[], int& n);

int findNum(int arr[], int& n);
Node modifyValuewithexcpt(int arr[], int& n);//Modify value at index with exception handling

void addNumwithexcpt(int arr[], int& n);//Add integer to end with exception handling
void removeNum(int arr[], int& n);

#endif // F_H