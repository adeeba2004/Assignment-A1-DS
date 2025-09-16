/**
 * @file main.cpp
 * CS-303 Assignment 1
 * Adeeba Nizam
 * 9/14/ 2025
 */

#include <iostream>
#include <fstream>
#include "f.h" 

using namespace std;

int main() {
    //cout << "CS-303 Assignment 1 - Array Operations" << endl;
    //cout << "======================================" << endl;

    int arr[10000];
    int n = 0; // FIXED: Initialize n to 0

    try {
        // Read from file
        cout << "\n1. Reading from A1input.txt..." << endl;
        readFile(arr, n);

        // Display array info
        cout << "Array size: " << n << endl;
        cout << "First 10 elements: ";
        for (int i = 0; i < min(10, n); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Finding function
        cout << "\n2. Testing Find Function" << endl;
        int index = findNum(arr, n);
        cout << index << endl;

        // Modify function with try-catch block
        cout << "\n3. Testing Modify Function with Exception Handling " << endl;
        try {
            Node m = modifyValuewithexcpt(arr, n);
            cout << "Modified value: " << m.new_val << endl;
            cout << "Old value: " << m.old_val << endl;
        }
        catch (const out_of_range& excpt) {
            cout << "Error: " << excpt.what() << endl;
        }

        //Add function with try-catch 
        cout << "\n4. Testing Add Function with Exception Handling " << endl;
        try {
            addNumwithexcpt(arr, n);
        }
        catch (const out_of_range& excpt) {
            cout << "Error: " << excpt.what() << endl;
        }

        //Remove function (FIXED from replace to remove)
        cout << "\n5. Testing Remove Function " << endl;
        try {
            removeNum(arr, n);
        }
        catch (const out_of_range& excpt) {
            cout << "Error: " << excpt.what() << endl;
        }

        // Show final array state
        cout << "\nFinal array size: " << n << endl;
        cout << "First 10 elements: ";
        for (int i = 0; i < min(10, n); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

    }
    catch (const runtime_error& e) {
        cout << "File Error: " << e.what() << endl;
        cout << "Make sure A1input.txt is in the same directory" << endl;
        return 1;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }



    return 0;

}
