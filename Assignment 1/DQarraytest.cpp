#include "Deque.h"
#include <iostream>

int main() {
    Deque<int> dq;

    // Enqueue some elements
    cout <<"Enqueue some elements \n";
    dq.enqueue(1);
    dq.enqueue(2);
    dq.enqueue(3);
    dq.display();  //Expected output: Size = 3, < 0=1 , 1=2 , 2=3 , >
    cout<<"\n\n";

    // Modify elements using []
    cout <<"Test: Array-like Access and Modification \n";
    cout << "\nBefore modification \n";
    dq.display();  //Expected output: Size = 3, < 0=1 , 1=2 , 2=3 , >
    cout<<"\n\n";
    dq[0] = 10;
    dq[1] = 20;
    cout << "After modification\n";
    dq.display(); // Expected output: Size = 3, < 0=10 , 1=20 , 2=3 , >

    return 0;
}
