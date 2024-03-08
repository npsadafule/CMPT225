#include "OSULL.h" 
#include "OSLL.h"  
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

const int ELEMENT_SIZE = sizeof(int); // Size of an element (integer) in bytes
// Aiming for a data structure size that significantly exceeds the cache sizes
// Sum of L1 instruction and data cache sizes in bytes is 196608 (128 KB + 64 KB)
// Assuming the data size to be at least 10 times this sum to exceed the cache
const int CACHE_SIZE = 196608; // Total cache size in bytes
const int DATA_MULTIPLIER = 10; // To ensure data size significantly exceeds cache size
const int NUM_ELEMENTS = (CACHE_SIZE * DATA_MULTIPLIER) / ELEMENT_SIZE;

int main() {
    OSULL<int> unrolledList;
    OSLL<int> linkedList;

    // Insert elements into the unrolled linked list
    auto start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        unrolledList.insert(i);
    }
    auto end = high_resolution_clock::now();
    auto insertDurationUnrolled = duration_cast<microseconds>(end - start).count();
    cout << "Unrolled Linked List insertion time: " << insertDurationUnrolled << " microseconds" << endl;

    // Insert elements into the doubly-linked list
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
    linkedList.insert(i);
    }
    end = high_resolution_clock::now();
    auto insertDurationLinked = duration_cast<microseconds>(end - start).count();
    cout << "Doubly-Linked List insertion time: " << insertDurationLinked << " microseconds" << endl;
    
    // Measure traversal time for the unrolled linked list
    start = high_resolution_clock::now();
    // Simulate traversal.
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        unrolledList.find(i);
    }
    end = high_resolution_clock::now();
    auto traversalDurationUnrolled = duration_cast<microseconds>(end - start).count();
    cout << "Unrolled Linked List traversal time: " << traversalDurationUnrolled << " microseconds" << endl;

    // Measure traversal time for the doubly-linked list
    start = high_resolution_clock::now();
    // Simulate traversal.
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        linkedList.find(i);
    }
    end = high_resolution_clock::now();
    auto traversalDurationLinked = duration_cast<microseconds>(end - start).count();
    cout << "Doubly-Linked List traversal time: " << traversalDurationLinked << " microseconds" << endl;

    return 0;
}