#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T, int initNodeCapacity = 10>
class OSULL {
public:
    OSULL() : size(0), nodeCapacity(initNodeCapacity) {
        // Initialize the dummy front and back nodes with 0 capacity for simplicity
        front = new Node(nullptr, nullptr, 0);
        back = new Node(nullptr, nullptr, 0);
        front->next = back;
        back->prev = front;
    }

    ~OSULL() {
        clear();
    }

    bool isEmpty() const {
        return size == 0;
    }

    int get_size() const {
        return size;
    }

    bool insert(T item) {
        Node* current = front->next;
        while (current != back && (current->data.size() == current->capacity || current->getMax() < item)) {
            current = current->next;
        }

        if (current == back || !current->insert(item)) {
            // Need to handle insertion in a new node or split existing node
            Node* newNode = current == back ? back->prev : current;
            if (newNode->data.size() == newNode->capacity) {
                newNode = splitNode(newNode);
            }
            newNode->insert(item);
            size++;
            return true;
        }

        size++;
        return true;
    }

    bool find(T item) {
        Node* current = front->next;
        while (current != back) {
            if (current->find(item)) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool remove(T item) {
        Node* current = front->next;
        while (current != back) {
            if (current->remove(item)) {
                size--;
                if (current->data.size() < nodeCapacity / 2) {
                    balanceOrMerge(current);
                }
                return true;
            }
            current = current->next;
        }
        return false;
    }

    T getMin() {
        return front->next->getMin();
    }

    T getMax() {
        return back->prev->getMax();
    }

    void display() {
        for (Node* current = front->next; current != back; current = current->next) {
            current->display();
            if (current->next != back) cout << " -> ";
        }
        cout << "\n";
    }

private:
    int size;
    int nodeCapacity;
    struct Node {
        vector<T> data;
        Node* prev;
        Node* next;
        int capacity;

        Node(Node* prev, Node* next, int capacity) : prev(prev), next(next), capacity(capacity) {
            data.reserve(capacity);
        }

        bool insert(T item) {
            if (std::find(data.begin(), data.end(), item) != data.end()) return false; // Item already exists
            data.push_back(item);
            std::sort(data.begin(), data.end());
            return true;
        }

        bool find(T item) {
            return std::find(data.begin(), data.end(), item) != data.end();
        }

        bool remove(T item) {
            auto it = std::find(data.begin(), data.end(), item);
            if (it != data.end()) {
                data.erase(it);
                return true;
            }
            return false;
        }

        T getMin() const { return data.front(); }
        T getMax() const { return data.back(); }

        void display() const {
            for (const T& val : data) {
                cout << val << (val != data.back() ? ", " : "");
            }
        }
    };

    Node* front;
    Node* back;

    Node* splitNode(Node* node) {
        Node* newNode = new Node(node, node->next, nodeCapacity);
        int splitIndex = node->data.size() / 2;
        newNode->data.assign(node->data.begin() + splitIndex, node->data.end());
        node->data.erase(node->data.begin() + splitIndex, node->data.end());

        if (node->next) {
            node->next->prev = newNode;
        }
        node->next = newNode;
        return newNode;
    }

    void balanceOrMerge(Node* node) {
    if (!node || node == front || node == back || node->data.empty()) return; // Safety check

    Node* prevNode = node->prev != front ? node->prev : nullptr;
    Node* nextNode = node->next != back ? node->next : nullptr;

    // Determine whether to balance with the previous or next node based on their fullness
    if (prevNode && !prevNode->data.empty() && (prevNode->data.size() > nodeCapacity / 2)) {
        // Borrow from the previous node
        T borrowedItem = prevNode->data.back();
        prevNode->data.pop_back();
        node->data.insert(node->data.begin(), borrowedItem);
        std::sort(node->data.begin(), node->data.end()); // Ensure data remains sorted
    } else if (nextNode && !nextNode->data.empty() && (nextNode->data.size() > nodeCapacity / 2)) {
        // Borrow from the next node
        T borrowedItem = nextNode->data.front();
        nextNode->data.erase(nextNode->data.begin());
        node->data.push_back(borrowedItem);
        std::sort(node->data.begin(), node->data.end()); // Ensure data remains sorted
    } else if (prevNode && (node->data.size() + prevNode->data.size() <= nodeCapacity)) {
        // Merge with the previous node if the total size doesn't exceed capacity
        mergeNodes(prevNode, node);
    } else if (nextNode && (node->data.size() + nextNode->data.size() <= nodeCapacity)) {
        // Merge with the next node if the total size doesn't exceed capacity
        mergeNodes(node, nextNode);
    }
}

void mergeNodes(Node* node1, Node* node2) {
    // Assumes node1 comes before node2 in the list
    for (T& item : node2->data) {
        node1->data.push_back(item);
    }
    std::sort(node1->data.begin(), node1->data.end()); // Ensure data remains sorted

    // Update pointers
    node1->next = node2->next;
    if (node2->next != nullptr) {
        node2->next->prev = node1;
    }

    delete node2; // Free the memory of the merged node

    if (node1->next == back) { // If node1 is now the last real node before the back dummy
        back->prev = node1;
    }
}


    void clear() {
        Node* current = front;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};