/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;

template <typename T, int initNodeCapacity = 10>
class OSULL {
   public:
      OSULL() {
         // set the node capacity
         nodeCapacity = initNodeCapacity;

         // make the front and back dummy nodes
         front = new Node(nullptr, nullptr, nodeCapacity);
         back = new Node(front, nullptr, nodeCapacity);
         front->next = back;

         size = 0;
         nodeCount = 0; // includes front and back dummy nodes
      }

      ~OSULL() {
         Node* cursor = front;
         while (cursor != nullptr) {
               Node* current = cursor;
               cursor = cursor->next;
               delete current;
         }
      }

      bool isEmpty() { return size == 0; }
      int get_size() { return size; }

      bool insert(T item) {
         Node* cursor = front->next;
         while (cursor != back) {
               if (cursor->size < cursor->capacity || cursor->next == back) {
                  if (cursor->insert(item)) {
                     size++;
                     return true;
                  } else {
                     return false; // Item already present
                  }
               }
               cursor = cursor->next;
         }
         return false;
      }

      bool find(T item) {
         Node* cursor = front->next;
         while (cursor != back) {
               if (cursor->find(item)) {
                  return true;
               }
               cursor = cursor->next;
         }
         return false;
      }

      bool remove(T item) {
         Node* cursor = front->next;
         while (cursor != back) {
               if (cursor->remove(item)) {
                  size--;
                  return true;
               }
               cursor = cursor->next;
         }
         return false;
      }

      T getMin() {
         // Requires: size not 0
         if (size <= 0) {
            cout << "List is empty. No Min element" << endl;
         }
         return front->next->getMin();
      }

      T getMax() {
         // Requires: size not 0
         if (size <= 0) {
            cout << "List is empty. No Max element" << endl;
         }
         return back->prev->getMax();
      }

      void display() {
         Node* cursor = front->next;
         cout << "<";
         while (cursor != back) {
               cursor->display();
               if (cursor->next != back) {
                  cout << ", ";
               }
               cursor = cursor->next;
         }
         cout << ">";
      }

   private:
      class Node {
      public:
         Node(Node* prev, Node* next, int capacity) {
               this->prev = prev;
               this->next = next;
               this->capacity = capacity;
               data = new T[capacity];
               size = 0;
         }
         ~Node() {
               delete[] data;
         }
         Node* prev;
         Node* next;
         int capacity;
         T* data;
         int size;

         bool insert(T item) {
            Node* cursor = front->next;
            while (cursor != back) {
               if (cursor->size < cursor->capacity || item < cursor->getMin()) {
                  if (cursor->insert(item)) {
                     size++;
                     return true;
                  }
                  return false; // Item is already present
               } 
               else if (cursor->size == cursor->capacity) {
                  // Handle full node: split node
                  Node* newNode = new Node(cursor, cursor->next, nodeCapacity);
                  // Distribute the elements between cursor and newNode
                  // Move half to the new node
                  int moveCount = cursor->size / 2;
                  for (int i = 0; i < moveCount; ++i) {
                     newNode->data[i] = cursor->data[cursor->size / 2 + i];
                     newNode->size++;
                     cursor->size--;
                  }
                  if (item > cursor->getMax()) {
                     newNode->insert(item);
                  } else {
                     cursor->insert(item);
                  }
                  newNode->next->prev = newNode;
                  cursor->next = newNode;
                  size++;
                  nodeCount++;
                  return true;
               }
               cursor = cursor->next;
            }
            return false;
         }

         bool find(T item) {
               for (int i = 0; i < size; i++) {
                  if (data[i] == item) {
                     return true;
                  }
               }
               return false;
         }

         bool remove(T item) {
            Node* cursor = front->next;
            while (cursor != back) {
               if (cursor->find(item) && cursor->remove(item)) {
                  size--;
                  if (cursor->size < nodeCapacity / 2) {
                     // If the node is less than half full after removal, try to rebalance or merge
                     if (cursor->prev != front && cursor->prev->size > nodeCapacity / 2) {
                        // Steal from the previous node
                        cursor->insert(cursor->prev->data[cursor->prev->size - 1]);
                        cursor->prev->remove(cursor->prev->data[cursor->prev->size - 1]);
                     } else if (cursor->next != back && cursor->next->size > nodeCapacity / 2) {
                        // Steal from the next node
                        cursor->insert(cursor->next->data[0]);
                        cursor->next->remove(cursor->next->data[0]);
                     } else {
                        // Merge with the next node if possible, or with the previous if next is the back dummy
                        Node* mergeTarget = cursor->next != back ? cursor : cursor->prev;
                        for (int i = 0; i < cursor->size; ++i) {
                              mergeTarget->insert(cursor->data[i]);
                        }
                        // Remove the current node
                        mergeTarget->next = cursor->next;
                        cursor->next->prev = mergeTarget;
                        delete cursor;
                        nodeCount--;
                     }
                  }
                  return true;
               }
               cursor = cursor->next;
            }
            return false;
         }

         void display() {
               for (int i = 0; i < size; i++) {
                  cout << data[i];
                  if (i < size - 1) {
                     cout << ", ";
                  }
               }
         }

         T getMin() {
               // Assumes non-empty node
               return data[0];
         }

         T getMax() {
               // Assumes non-empty node
               return data[size - 1];
         }
      };

      int size; // current number of items
      int nodeCount; // current number of nodes
      int nodeCapacity; // capacity to assign to new nodes
      Node* front; // pointer to front dummy node
      Node* back;  // pointer to back dummy node
};