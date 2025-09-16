#include <iostream>
#include <fstream>
#include "f.h"  

using namespace std;

int main() {
    int arr[10000]; // Array with large enough capacity
    int n = 0;      // Tracks current size of array

    // 1) Read input file into array
    readFile(arr, n);

    // 2) Search for a number in array
    cout << findNum(arr, n) << endl;

    // 3) Modify a number at given index (exception handled)
    try {
        Node m = modifyValuewithexcpt(arr, n);
        cout << "Modified value: " << m.new_val << endl
            << "Old value: " << m.old_val << endl;
    }
    catch (out_of_range excpt) {
        cout << excpt.what() << endl; // Print error message
    }

    // 4) Append a new number at the end (exception handled)
    try {
        addNumwithexcpt(arr, n);
    }
    catch (out_of_range excpt) {
        cout << excpt.what() << endl;
    }

    // 5) Remove number at given index (exception handled)
    try {
        removeNum(arr, n);
    }
    catch (out_of_range excpt) {
        cout << excpt.what() << endl;
    }

    cout << endl;
    return 0;
}
