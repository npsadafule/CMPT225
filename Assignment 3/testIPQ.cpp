#include "IPQ.h" // Assuming the IPQ implementation is saved in IPQ.h
#include <cassert>
#include <string>
#include <iostream>

void testInsertAndGetMin() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    assert(ipq.getMin() == "task3" && "getMin should return the task with lowest priority.");
    std::cout << "testInsertAndGetMin passed." << std::endl;
}

void testDeleteMin() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    std::string minTask = ipq.deleteMin();
    assert(minTask == "task3" && "deleteMin should remove and return the task with lowest priority.");
    assert(ipq.size() == 2 && "Size should be 2 after one deletion.");
    std::cout << "testDeleteMin passed." << std::endl;
}

void testUpdatePriority() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    ipq.updatePriority("task1", 5);
    assert(ipq.getMin() == "task1" && "getMin should return 'task1' after priority update.");
    std::cout << "testUpdatePriority passed." << std::endl;
}

void testRemove() {
    IPQ<> ipq;
    ipq.insert("task1", 30);
    ipq.insert("task2", 20);
    ipq.insert("task3", 10);

    ipq.remove("task2");
    assert(ipq.size() == 2 && "Size should be 2 after removing 'task2'.");
    std::cout << "testRemove passed." << std::endl;
}

void testIsEmptyAndClear() {
    IPQ<> ipq;
    assert(ipq.isEmpty() == true && "isEmpty should return true for a new IPQ.");

    ipq.insert("task1", 30);
    assert(ipq.isEmpty() == false && "isEmpty should return false after insertion.");

    ipq.clear();
    assert(ipq.isEmpty() == true && "isEmpty should return true after clear.");
    std::cout << "testIsEmptyAndClear passed." << std::endl;
}

void testReserve() {
    IPQ<> ipq;
    ipq.reserve(20);
    // This test is to ensure no exceptions or errors; direct observable behavior from reserve is hard to assert.
    std::cout << "testReserve passed." << std::endl;
}

int main() {
    testInsertAndGetMin();
    testDeleteMin();
    testUpdatePriority();
    testRemove();
    testIsEmptyAndClear();
    testReserve();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
