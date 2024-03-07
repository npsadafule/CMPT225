#include "OSULL.h"
#include <iostream>

using namespace std;

int main() {
    OSULL<int> lst;

    cout << "Initially, the list is: ";
    lst.display();

    // Insert elements
    for (int i = 1; i <= 10; ++i) {
        lst.insert(i * 2); // Insert even numbers between 2 and 20
    }
    cout << "After inserting even numbers from 2 to 20: ";
    lst.display();

    // Attempt to find elements
    cout << "Finding 4: " << (lst.find(4) ? "Found" : "Not found") << endl;
    cout << "Finding 5: " << (lst.find(5) ? "Found" : "Not found") << endl; // 5 is not in the list

    // Remove elements
    lst.remove(4);
    lst.remove(10);
    cout << "After removing 4 and 10: ";
    lst.display();

    // Insert more elements
    lst.insert(5);
    lst.insert(15);
    cout << "After inserting 5 and 15: ";
    lst.display();

    // Testing Min and Max
    try {
        cout << "Min: " << lst.getMin() << endl;
        cout << "Max: " << lst.getMax() << endl;
    } catch (const std::exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // Testing on an empty list
    OSULL<int> emptyList;
    cout << "Testing on an empty list:\n";
    try {
        cout << "Min: " << emptyList.getMin() << endl;
    } catch (const std::exception& e) {
        cout << "Exception caught trying to get min from an empty list: " << e.what() << endl;
    }

    try {
        cout << "Max: " << emptyList.getMax() << endl;
    } catch (const std::exception& e) {
        cout << "Exception caught trying to get max from an empty list: " << e.what() << endl;
    }

    cout << "Finding 10 in an empty list: " << (emptyList.find(10) ? "Found" : "Not found") << endl;
    cout << "Removing 10 from an empty list: " << (emptyList.remove(10) ? "Removed" : "Not found") << endl;

    cout << "Done with all tests.\n";

    return 0;
}