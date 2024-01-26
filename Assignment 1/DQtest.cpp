#include "Deque.h"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Creates an empty deque and displays it
    Deque<int> dq1;
    cout << "Test 1: Empty Deque \n";
    dq1.display(); // Expected output: Size = 0, < >
    cout<<"\n\n";

    // Test 2: Enqueue elements to the back
    dq1.enqueue(1);
    dq1.enqueue(2);
    dq1.enqueue(3);
    cout << "Test 2: Enqueue to Back \n";
    dq1.display(); // Expected output: Size = 3, < 0=1 , 1=2 , 2=3 , >
    cout<<"\n\n";

    // Test 3: Dequeue from the front
    int frontElement = dq1.dequeue();
    cout << "Test 3: Dequeue from Front \n";
    cout << "Front element: " << frontElement << "\n"; //Expected output: Front element: 1
    dq1.display(); // Expected output: Size = 2, < 0=2 , 1=3 , >
    cout<<"\n\n";

    // Test 4: Jump to the front
    dq1.jump(7);
    cout <<"Test 4: Jump to Front \n";
    dq1.display(); // Expected output: Size = 3, < 0=7 , 1=2 , 2=3 , >
    cout<<"\n\n";

    // Test 5: Eject from the back
    int backElement = dq1.eject();
    cout << "Test 5: Eject from Back \n";
    cout << "Back element: " << backElement << "\n"; //Expected output: Back element: 3
    dq1.display(); // Expected output: Size = 2, < 0=7 , 1=2 , >
    cout<<"\n\n";

    // Test 6: Clear the deque
    dq1.clear();
    cout << "Test 6: Clear Deque \n";
    dq1.display(); // Expected output: Size = 0, < >
    cout<<"\n";

    // Test 7: Enqueue more elements to test reserve
    for (int i = 1; i <= 10; ++i) {
        dq1.enqueue(i);
    }
    cout << "\nTest 7: Enqueue to prompt Reserve \n";
    dq1.display(); // Expected output: Size = 10, < 0=1 , 1=2 , 2=3 , 3=4 , 4=5 , 5=6 , 6=7 , 7=8 , 8=9 , 9=10 , >
    cout<<"\n\n";

    // Test 8: Wrap-around
    dq1.jump(100);
    dq1.enqueue(101);
    cout << "Test 8: Wrap-around \n";
    dq1.display(); // Expected output: Size = 12, < 0=100 , 1=1 , 2=2 , 3=3 , 4=4 , 5=5 , 6=6 , 7=7 , 8=8 , 9=9 , 10=10 , 11=101 , >
    cout<<"\n\n";

    // Test 9: Reserve
    dq1.reserve(20);
    cout << "Test 9: Reserve \n";
    dq1.display(); // Expected output: Size = 12, < 0=100 , 1=1 , 2=2 , 3=3 , 4=4 , 5=5 , 6=6 , 7=7 , 8=8 , 9=9 , 10=10 , 11=101 , >
    cout<<"\n\n";

    // Test 10: Long sequence of operations
    for (int i = 0; i < 30; ++i) {
        if (i % 2 == 0) {
            dq1.enqueue(i);
        } else {
            dq1.jump(i);
        }
    }
    cout << "Test 10: Long sequence of operations \n";
    dq1.display(); // Expected output: Size = 42, < 0=29 , 1=27 , 2=25 , 3=23 , 4=21 , 5=19 , 6=17 , 7=15 , 8=13 , 9=11 , 10=9 , 11=7 , 12=5 , 13=3 , 14=1 , 15=100 , 16=1 , 17=2 , 18=3 , 19=4 , 20=5 , 21=6 , 22=7 , 23=8 , 24=9 , 25=10 , 26=101 , 27=0 , 28=2 , 29=4 , 30=6 , 31=8 , 32=10 , 33=12 , 34=14 , 35=16 , 36=18 , 37=20 , 38=22 , 39=24 , 40=26 , 41=28 , >
    cout<<"\n\n";

    return 0;
}

