#include "Deque.h"
#include <iostream>

int main() {
    Deque<int> dq;

    // Enqueue some elements
    dq.enqueue(1);
    dq.enqueue(2);
    dq.enqueue(3);

    // Modify elements using []
    dq[0] = 10;
    dq[1] = 20;

    // Display elements
    dq.display(); // Expected output: 10 20 3

    return 0;
}
