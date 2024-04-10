# Deque Class Testing Report

## Introduction

This document describes the testing process and results for the Deque class implemented using a dynamic circular array. The Deque supports operations for adding and removing elements from both the front and back ends, dynamic resizing, and array-like element access.

## Test Environment

- **Compiler**: g++
- **Standard**: C++17
- **Operating System**: Linux Ubuntu 20.04

## Test Cases

### `DQtest.cpp`

#### Test 1: Empty Deque
- **Description**: Creates an empty deque and verifies that its size is 0.
- **Expected Outcome**: The deque starts in an empty state, confirming correct initialization.

#### Test 2: Enqueue to Back
- **Description**: Enqueues three elements to the back of the deque and displays the contents.
- **Expected Outcome**: Basic enqueue functionality is confirmed, elements are successfully added to the back.

#### Test 3: Dequeue from Front
- **Description**: Dequeues an element from the front and ensures the deque is updated correctly.
- **Expected Outcome**: Proper functioning of the dequeue operation and correct adjustment of the deque size.

#### Test 4: Jump to Front
- **Description**: Uses the `jump` operation to add an element to the front of the deque.
- **Expected Outcome**: The deque supports jumping operations, allowing elements to be added to the front effectively.

#### Test 5: Eject from Back
- **Description**: Ejects an element from the back and ensures the deque is updated accordingly.
- **Expected Outcome**: Ability to remove elements from the back of the deque is checked.

#### Test 6: Clear Deque
- **Description**: Clears the deque and verifies that its size becomes 0.
- **Expected Outcome**: Clear operation effectively removes all elements, resulting in an empty deque.

#### Test 7: Enqueue to Prompt Reserve
- **Description**: Enqueues 10 elements to the deque to trigger a resize and tests the reserve functionality.
- **Expected Outcome**: The deque dynamically adjusts its capacity to accommodate additional elements.

#### Test 8: Wrap-around
- **Description**: Demonstrates the wrap-around behavior by jumping to a position beyond the current front and enqueuing an element.
- **Expected Outcome**: Confirms the deque's ability to handle elements positioned before the front correctly.

#### Test 9: Reserve
- **Description**: Attempts to reserve additional capacity for the deque.
- **Expected Outcome**: Checks that the reserve operation behaves as expected when the current size is less than the requested capacity.

#### Test 10: Long Sequence of Operations
- **Description**: Performs a long sequence of enqueue and jump operations, testing the deque's ability to handle multiple operations and wrap-arounds.
- **Expected Outcome**: Ensures the correctness of the deque under a variety of scenarios.

### `DQarraytest.cpp`

#### Array-like Access and Modification
- **Description**: Tests the array-like access and modification using the `[]` operator.
    - **Enqueue some elements**: Enqueues three elements (1, 2, and 3) into the deque.
    - **Array-like Access and Modification**: Modifies the first two elements in the deque to 10 and 20, respectively, using the `[]` operator.
- **Expected Outcome**: Before modification, the current state of the deque is displayed showcasing the original elements. After modification, the updated state confirms the changes made to the elements.

## Conclusion

The Deque class has been rigorously tested across multiple scenarios to ensure its robustness and correctness. The implementation handles dynamic resizing, multiple access methods, and proper queue operations efficiently. This report verifies the functionality through detailed and structured testing.
