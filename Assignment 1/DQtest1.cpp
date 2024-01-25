#include <iostream>
#include "Deque.h"

using namespace std;

int main() {
    // Creating a Deque
    Deque<int> dq;

    cout<<"Test 1: Enqueue and dequeue a few elements "<<endl;
    dq.enqueue(1);
    dq.enqueue(2);
    dq.enqueue(3);
    dq.display();  // Expected output: Size = 3 < 0=1 , 1=2 , 2=3 , >
    cout<<"\n";

    int frontElement = dq.dequeue();
    cout << "Front element: " << frontElement <<endl;  // Expected output: Front element: 1
    dq.display();  // Expected output: Size = 2 < 0=2 , 1=3 , >
    cout<<"\n"<<"\n";

    cout<<"Test 2: Test jump and eject" <<endl;
    dq.jump(0);
    dq.display();  // Expected output: Size = 3 < 0=0 , 1=2 , 2=3 , >
    cout<<"\n";

    int backElement = dq.eject();
    cout << "Back element: " << backElement <<endl;  // Expected output: Back element: 3
    dq.display();  // Expected output: Size = 2 < 0=0 , 1=2 , >
    cout<<"\n"<<"\n";

    cout<<"Test 3: Test wrap-around" <<endl;
    for (int i = 4; i <= 10; ++i) {
        dq.enqueue(i);
    }
    dq.display();  // Expected output: Size = 9 < 0=0 , 1=2 , 2=4 , 3=5 , 4=6 , 5=7 , 6=8 , 7=9 , 8=10 , >
    cout<<"\n"<<"\n";

    cout<<"Test 4: Test reserve" <<endl;
    dq.reserve(15);
    dq.display();  // Expected output: Size = 9 < 0=0 , 1=2 , 2=4 , 3=5 , 4=6 , 5=7 , 6=8 , 7=9 , 8=10 , >
    cout<<"\n"<<"\n";

    cout<<"Test 5: Long sequence of operations"<<endl;
    for (int i = 11; i <= 20; ++i) {
        dq.jump(i);
    }
    dq.display();  // Expected output: Size = 19 < 0=20 , 1=19 , 2=18 , 3=17 , 4=16 , 5=15 , 6=14 , 7=13 , 8=12 , 9=11 , 10=0 , 11=2 , 12=4 , 13=5 , 14=6 , 15=7 , 16=8 , 17=9 , 18-10 , >
    cout<<"\n"<<"\n";

    cout<<"Some additional Edge Cases" <<endl;

    cout<<"Case 1: Empty Deque" <<endl;
    Deque<int> dq1;
    cout << "Is dq1 empty? " << (dq1.empty() ? "Yes" : "No") <<endl;  // Expected output: Yes
    cout<<"\n";

    cout<<"Case 2: Edge Case with Reserve" <<endl;
    dq.reserve(5);  // Trying to reserve with a new capacity less than the current size
    dq.display();  // Expected output: Size = 19 < 0=20 , 1=19 , 2=18 , 3=17 , 4=16 , 5=15 , 6=14 , 7=13 , 8=12 , 9=11 , 10=0 , 11=2 , 12=4 , 13=5 , 14=6 , 15=7 , 16=8 , 17=9 , 18-10 , >
    cout<<"\n"<<"\n";

    cout<<"Case 3: Edge Case with Jump" <<endl;
    Deque<int> dq2;
    dq2.jump(5);  // Trying to jump when the deque is empty
    dq2.display();  // Expected output: Size = 1 < 0=5 , >
    cout<<"\n"<<"\n";

    cout<<"Case 4: Edge Case with Enqueue and Dequeue" <<endl;
    Deque<int> dq3;
    dq3.enqueue(10);
    int dqElement = dq3.dequeue();
    cout << "Dequeued element: " << dqElement <<endl;  // Expected output: Dequeued element: 10
    dq3.display();  // Expected output: Size = 0 < >
    cout<<"\n"<<"\n";

    return 0;
}
