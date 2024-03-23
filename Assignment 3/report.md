# Documentation of IPQ Class Design and Testing Regimen

Author: Neel Sadafule  
Date: March 22, 2024

## IPQ Class Design Choices

The IPQ (Indexed Priority Queue) class implementation is designed to efficiently manage a collection of tasks, each identified by a unique string identifier "tid" and associated with a priority value. The design is structured around two main components: a min-heap for priority management and an unordered map for indexing. Below are the key design choices and their justifications:

- **Template for Initial Capacity:** The class is templated with an "initialSize" parameter, allowing users to set an initial capacity. This can improve memory usage and performance for known workload sizes by minimizing unnecessary allocations.

- **Use of Min-Heap:** A binary heap is chosen to manage priorities due to its efficient support for the fundamental operations of a priority queue: insertion, deletion of the minimum, and priority update. These operations can be performed in logarithmic time complexity, making the heap an ideal data structure for priority management.

- **Use of Unordered Map:** An unordered map ”map ” maps task IDs to their corresponding indices in the heap array. This index tracking enables direct access to any task in the heap, allowing efficient priority updates and deletions, which would otherwise require a linear search.

- **Node Structure:** Each element in the heap is a "Node" struct containing a priority and a task ID. This encapsulation keeps related data together, simplifying heap management.

- **Recursive Percolate Up/Down:** The "percolateUp" and "percolateDown" operations are implemented recursively. While iterative solutions are more common due to their efficiency in practice, the recursive approach is chosen here to demonstrate understanding and proficiency with recursion.

- **Exception Handling:** The implementation includes exception handling for various error conditions (e.g., inserting a duplicate task ID, attempting operations on an empty queue). This ensures the class behaves predictably and safely.

- **Swap Method:** A private swap method is used to exchange two nodes within the heap. This method not only swaps the nodes but also updates the map to keep the index references correct. This encapsulation of swapping logic ensures consistency and reduces code duplication.

## Testing Regimen Design

The testing regimen for the IPQ class is designed to be comprehensive, covering all public methods and their expected behaviors, including edge cases. The goals of the testing design include ensuring correctness, robustness, and highlighting any potential design flaws. Key aspects of the testing design are:

- **Method-by-Method Testing:** Individual tests for each public method help isolate issues effectively.

- **Assertion-Based Validation:** Each test function uses assertions to validate the expected outcomes of operations. Assertions provide a clear, straightforward way to verify correctness and halt execution with informative feedback if a test fails.

- **Testing Edge Cases:** The tests include edge cases such as inserting duplicate task IDs, removing tasks from an empty queue, and updating priorities in various situations. These tests ensure the class handles exceptional conditions correctly.

- **Sequential Operation Testing:** Some tests perform a sequence of operations to simulate more complex usage scenarios and verify that the class maintains a correct state throughout. For example, a test might insert several tasks, update priorities, remove a task, and then validate the remaining tasks’ order.

- **Memory and Capacity Management:** While direct observation of memory usage and dynamic capacity changes (e.g., via the "reserve" method) is challenging in a simple test suite, tests are designed to indirectly ensure that these aspects do not lead to errors or unexpected behavior.

- **Robustness and Error Handling:** The testing regimen includes scenarios designed to trigger exception throwing, ensuring the class handles invalid operations correctly.