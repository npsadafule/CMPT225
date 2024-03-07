#include <iostream>
#include <cassert>
#include "OSULL.h"

using namespace std;

// Function to run tests on the OSULL class
void test_OSULL() {
    OSULL<int> osull;

    // Test insertion
    osull.insert(5);
    osull.insert(10);
    osull.insert(3);
    osull.insert(8);
    osull.insert(15);

    // Test display
    cout << "OSULL after insertion: ";
    osull.display(); // Should print <3 5 8 10 15>
    assert(osull.get_size() == 5);

    // Test removal
    osull.remove(8);
    osull.remove(3);

    // Test display after removal
    cout << "OSULL after removal: ";
    osull.display(); // Should print <5 10 15>
    assert(osull.get_size() == 3);

    // Test searching
    cout << "Is 10 present in OSULL? " << (osull.find(10) ? "Yes" : "No") << endl; // Should print "Yes"
    cout << "Is 3 present in OSULL? " << (osull.find(3) ? "Yes" : "No") << endl;   // Should print "No"

    // Test merging and splitting
    osull.insert(20);
    osull.insert(25);
    osull.insert(30);
    osull.insert(35);
    osull.insert(40);

    // Test display after additional insertion
    cout << "OSULL after additional insertion: ";
    osull.display(); // Should print <5 10 15 20 25 30 35 40>
    assert(osull.get_size() == 8);

    // Test removal that triggers merging
    osull.remove(20);
    osull.remove(25);

    // Test display after removal triggering merging
    cout << "OSULL after removal triggering merging: ";
    osull.display(); // Should print <5 10 15 30 35 40>
    assert(osull.get_size() == 6);

    // Test insertion that triggers splitting
    osull.insert(7);
    osull.insert(12);

    // Test display after insertion triggering splitting
    cout << "OSULL after insertion triggering splitting: ";
    osull.display(); // Should print <5 7 10 12 15 30 35 40>
    assert(osull.get_size() == 8);

    // Test getMin and getMax
    cout << "Minimum value in OSULL: " << osull.getMin() << endl; // Should print "5"
    cout << "Maximum value in OSULL: " << osull.getMax() << endl; // Should print "40"
}

int main() {
    // Run tests on OSULL class
    test_OSULL();

    cout << "All tests passed successfully!" << endl;

    return 0;
}
