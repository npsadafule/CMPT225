#include "IPQ.h" 
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

void testInsertAndGetMin() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    assert(ipq.getMin() == "task3" && "getMin should return the task with lowest priority.");
    cout << "testInsertAndGetMin passed." << endl;
}

void testDeleteMin() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    string minTask = ipq.deleteMin();
    assert(minTask == "task3" && "deleteMin should remove and return the task with lowest priority.");
    assert(ipq.size() == 2 && "Size should be 2 after one deletion.");
    cout << "testDeleteMin passed." << endl;
}

void testUpdatePriority() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    ipq.updatePriority("task1", 5);
    assert(ipq.getMin() == "task1" && "getMin should return 'task1' after priority update.");
    cout << "testUpdatePriority passed." << endl;
}

void testRemove() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    ipq.remove("task2");
    assert(ipq.size() == 2 && "Size should be 2 after removing 'task2'.");
    cout << "testRemove passed." << endl;
}

void testIsEmptyAndClear() {
    IPQ<> ipq;
    assert(ipq.isEmpty() == true && "isEmpty should return true for a new IPQ.");

    ipq.insert("task1", 30);
    assert(ipq.isEmpty() == false && "isEmpty should return false after insertion.");

    ipq.clear();
    assert(ipq.isEmpty() == true && "isEmpty should return true after clear.");
    cout << "testIsEmptyAndClear passed." << endl;
}

void testReserve() {
    IPQ<> ipq;
    ipq.reserve(20);
    cout << "testReserve passed." << endl;
}

int main() {
    testInsertAndGetMin();
    testDeleteMin();
    testUpdatePriority();
    testRemove();
    testIsEmptyAndClear();
    testReserve();

    cout << "All tests passed successfully!" << endl;
    return 0;
}
