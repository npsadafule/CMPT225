#include "OSULL.h" 
#include "OSLL.h"  
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

const int num = 100000; // Number of elements to insert

int main() {
    OSULL<int> unrolledList;
    OSLL<int> linkedList;

    // Insert elements into the unrolled linked list
    auto start = high_resolution_clock::now();
    for (int i = 0; i < num; ++i) {
        unrolledList.insert(i);
    }
    auto end = high_resolution_clock::now();
    auto insertDurationUnrolled = duration_cast<microseconds>(end - start).count();
    cout << "Unrolled Linked List insertion time: " << insertDurationUnrolled << " microseconds" << endl;

    // Insert elements into the doubly-linked list
    start = high_resolution_clock::now();
    for (int i = 0; i < num; ++i) {
        linkedList.insert(i);
    }
    end = high_resolution_clock::now();
    auto insertDurationLinked = duration_cast<microseconds>(end - start).count();
    cout << "Doubly-Linked List insertion time: " << insertDurationLinked << " microseconds" << endl;

    // Measure traversal time for the unrolled linked list
    start = high_resolution_clock::now();
    for (int i = 0; i < num; ++i) {
        unrolledList.find(i);
    }
    end = high_resolution_clock::now();
    auto traversalDurationUnrolled = duration_cast<microseconds>(end - start).count();
    cout << "Unrolled Linked List traversal time: " << traversalDurationUnrolled << " microseconds" << endl;

    // Measure traversal time for the doubly-linked list
    start = high_resolution_clock::now();
    for (int i = 0; i < num; ++i) {
        linkedList.find(i);
    }
    end = high_resolution_clock::now();
    auto traversalDurationLinked = duration_cast<microseconds>(end - start).count();
    cout << "Doubly-Linked List traversal time: " << traversalDurationLinked << " microseconds" << endl;

    return 0;
}