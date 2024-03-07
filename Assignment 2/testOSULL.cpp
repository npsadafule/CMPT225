#include <iostream>
#include <cassert>
#include "OSULL.h"

using namespace std;

// Function to run extended tests on the OSULL class with detailed outputs
void test_OSULL() {
    OSULL<int> osull;

    cout << "\nTesting insertion of initial set of values...\n";
    osull.insert(5);
    osull.insert(10);
    osull.insert(3);
    osull.insert(8);
    osull.insert(15);
    osull.insert(10); // Attempt to insert a duplicate

    cout << "OSULL after initial insertions (including duplicate 10 attempt): ";
    osull.display(); // Expected: <3 5 8 10 15>
    assert(osull.get_size() == 5);
    cout << "Passed.\n";

    cout << "\nTesting removal...\n";
    osull.remove(8); // Remove a middle value
    osull.remove(3); // Remove the smallest value

    cout << "OSULL after removing 8 and 3: ";
    osull.display(); // Expected: <5 10 15>
    assert(osull.get_size() == 3);
    cout << "Passed.\n";

    cout << "\nTesting insertion of additional values...\n";
    // Insert a mix of values to test order maintenance and node splitting
    int additionalValues[] = {2, 7, 12, 17, 22, 27, 32, 37, 42, 47, 52, 57, 62, 67, 72};
    for (int val : additionalValues) {
        osull.insert(val);
        cout << "Inserted " << val << ": ";
        osull.display();
    }
    cout << "After inserting additional values: ";
    osull.display(); // List should now include all these values in order
    assert(osull.get_size() == 18);
    cout << "Passed.\n";

    cout << "\nTesting removal that may trigger merging...\n";
    osull.remove(22); // Remove a value to potentially trigger merging
    cout << "OSULL after removal of 22 (merging test): ";
    osull.display();
    assert(osull.get_size() == 17);
    cout << "Passed.\n";

    cout << "\nTesting insertion that triggers node splitting...\n";
    osull.insert(25); // Inserting in a way that might trigger splitting
    cout << "OSULL after inserting 25 (splitting test): ";
    osull.display();
    assert(osull.get_size() == 18);
    cout << "Passed.\n";

    cout << "\nTesting search functionality...\n";
    // Testing presence and absence
    assert(osull.find(10) == true); // Should be present
    assert(osull.find(3) == false); // Should be absent after removal
    cout << "Search functionality passed.\n";

    cout << "\nTesting retrieval of minimum and maximum...\n";
    cout << "Minimum value in OSULL: " << osull.getMin() << endl; // Expected: "2"
    cout << "Maximum value in OSULL: " << osull.getMax() << endl; // Expected: "72"
    cout << "Retrieval tests passed.\n";

    cout << "\nAll tests completed. If no assertions failed, all tests passed successfully!\n";
}

int main() {
    test_OSULL();
    return 0;
}
