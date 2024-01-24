#include "Deque.h"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Creates an empty deque and displays it
    Deque<int> dq1;
    cout << "Test 1: Empty Deque \n";
    dq1.display(); // Expected output: (empty line)
    cout << "\n";

    // Test 2: Enqueue elements to the back
    dq1.enqueue(1);
    dq1.enqueue(2);
    dq1.enqueue(3);
    cout << "Test 2: Enqueue to Back \n";
    dq1.display(); // Expected output: 1 2 3
    cout << "\n";

    // Test 3: Dequeue from the front
    int frontElement = dq1.dequeue();
    cout << "Test 3: Dequeue from Front \n";
    cout << "Front element: " << frontElement << "\n"; // Expected output 1
    dq1.display(); // Expected output: 2 3
    cout << "\n";

    // Test 4: Jump to the front
    dq1.jump(7);
    cout << "Test 4: Jump to Front \n";
    dq1.display(); // Expected output: 7 2 3
    cout << "\n";

    // Test 5: Eject from the back
    int backElement = dq1.eject();
    cout << "Test 5: Eject from Back \n";
    cout << "Back element: " << backElement << "\n"; // Expected output 3
    dq1.display(); // Expected output: 7 2
    cout << "\n";

    // Test 6: Clear the deque
    dq1.clear();
    cout << "Test 6: Clear Deque \n";
    dq1.display(); // Expected output: empty line
    cout << "\n";

    // Test 7: Enqueue more elements to test reserve
    for (int i = 1; i <= 10; ++i) {
        dq1.enqueue(i);
    }
    cout << "Test 7: Enqueue to prompt Reserve \n";
    dq1.display(); // Displays resized deque
    cout << "\n";

    // Test 8: Array-like access
    cout << "Test 8: Array-Like Access\n";
    for (int i = 0; i < dq1.size(); ++i) {
        cout << dq1[i] << " ";
    }
    cout << "\n";

    // Test 9: Test reserve with smaller capacity
    dq1.reserve(5);
    cout << "Test 9: Reserve with Smaller Capacity \n";
    dq1.display(); // Displays deque with resized capacity
    cout << "\n";

    // Test 10: Test reserve with same capacity
    dq1.reserve(8);
    cout << "Test 10: Reserve with Same Capacity \n";
    dq1.display(); // Displays deque with same capacity
    cout << "\n";

    // Test 11: Test reserve with larger capacity
    dq1.reserve(15);
    cout << "Test 11: Reserve with Larger Capacity \n";
    dq1.display(); // Displays deque with larger capacity
    cout << "\n";

    return 0;
}
