#include "Deque.h"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Creates an empty deque and displays it
    Deque<int> dq1;
    cout << "Test 1: Empty Deque \n";
    dq1.display(); // Expected output: (empty line)
    cout<<"\n";

    // Test 2: Enqueue elements to the back
    dq1.enqueue(1);
    dq1.enqueue(2);
    dq1.enqueue(3);
    cout << "Test 2: Enqueue to Back \n";
    dq1.display(); // Expected output: 1 2 3
    cout<<"\n";

    // Test 3: Dequeue from the front
    int frontElement = dq1.dequeue();
    cout << "Test 3: Dequeue from Front \n";
    cout << "Front element: " << frontElement << "\n"; //Expected output 1
    dq1.display(); // Expected output: 2 3
    cout<<"\n";

    // Test 4: Jump to the front
    dq1.jump(7);
    cout <<"Test 4: Jump to Front \n";
    dq1.display(); // Expected output: 7 2 3
    cout<<"\n";

    // Test 5: Eject from the back
    int backElement = dq1.eject();
    cout << "Test 5: Eject from Back \n";
    cout << "Back element: " << backElement << "\n"; //Expected output 3
    dq1.display(); // Expected output: 7 2
    cout<<"\n";

    // Test 6: Clear the deque
    dq1.clear();
    cout << "Test 6: Clear Deque \n";
    dq1.display(); // Expected output: empty line

    // Test 7: Enqueue more elements to test reserve
    for (int i = 1; i <= 10; ++i) {
        dq1.enqueue(i);
    }
    cout << "\nTest 7: Enqueue to prompt Reserve \n";
    dq1.display(); // Displays resized deque

    // Test 8: Array-like access
    cout << "\nTest 8: Array-Like Access\n";
    for (int i = 0; i < dq1.size(); ++i) {
        cout << dq1[i] << " ";
    }
    cout << "\n";

    return 0;
}
