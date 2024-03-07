#include <iostream>
#include <algorithm> // For std::sort
#include <cassert> // For assert
using namespace std;

template <typename T, int initNodeCapacity = 10>
class OSULL {
   public:
         OSULL() {
            nodeCapacity = initNodeCapacity;
            front = new Node(nullptr, nullptr, nodeCapacity);
            back = new Node(front, nullptr, nodeCapacity);
            front->next = back;
            size = 0;
            nodeCount = 0;
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
            while (cursor != back && cursor->getMax() < item) {
               cursor = cursor->next;
            }

            if (cursor != back && cursor->find(item)) {
               return false; // Item already exists
            }

            if (cursor->size == cursor->capacity) {
               // Split node if full
               Node* newNode = new Node(cursor, cursor->next, nodeCapacity);
               cursor->next->prev = newNode;
               cursor->next = newNode;
               nodeCount++;

               // Redistribute items
               T* temp = new T[cursor->capacity + 1];
               for (int i = 0; i < cursor->size; i++) {
                     temp[i] = cursor->data[i];
               }
               temp[cursor->size] = item;
               std::sort(temp, temp + cursor->size + 1); // Make sure items are sorted

               cursor->size = (cursor->size + 1) / 2;
               newNode->size = (cursor->size + 1) - cursor->size;
               for (int i = 0; i < cursor->size; i++) {
                     cursor->data[i] = temp[i];
               }
               for (int i = 0; i < newNode->size; i++) {
                     newNode->data[i] = temp[i + cursor->size];
               }

               delete[] temp;
            } else {
               // Insert in the correct position
               int pos = 0;
               while (pos < cursor->size && cursor->data[pos] < item) {
                     pos++;
               }
               for (int i = cursor->size; i > pos; i--) {
                     cursor->data[i] = cursor->data[i - 1];
               }
               cursor->data[pos] = item;
               cursor->size++;
            }
            size++;
            return true;
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
               if (cursor->find(item)) {
                  bool removed = cursor->remove(item);
                  if (!removed) {
                     return false; // Item not found in this node, though it should never happen due to find check
                  }
                  size--;
                  // Check if redistribution or merging is needed
                  if (cursor->size < cursor->capacity / 2) {
                     adjustAfterRemoval(cursor);
                  }
                  return true;
               }
               cursor = cursor->next;
            }
            return false; // Item not found in any node
         }

         T getMin() {
            return front->next->getMin();
         }

         T getMax() {
            return back->prev->getMax();
         }

         void display() {
            Node* cursor = front->next;
            cout << "<";
            while (cursor != back) {
               cursor->display();
               cursor = cursor->next;
            }
            cout << ">";
         }

   private:
      class Node {
      public:
         Node* prev;
         Node* next;
         int capacity;
         T* data;
         int size;

         Node(Node* prev, Node* next, int capacity) : prev(prev), next(next), capacity(capacity), size(0) {
            data = new T[capacity];
         }

         ~Node() {
            delete[] data;
         }
         
      void adjustAfterRemoval(Node* node) {
         if (node->size == 0) {
            // Remove node if empty
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            nodeCount--;
         } 
         else {
            // Try to redistribute or merge with previous node if not the first node
            Node* prevNode = node->prev;
            if (prevNode != front && (prevNode->size + node->size) <= nodeCapacity) {
                // Merge node with previous node
                mergeNodes(prevNode, node);
            } 
            else if (prevNode != front && prevNode->size > nodeCapacity / 2) {
                // Redistribute items between prevNode and node
                redistributeNodes(prevNode, node);
            }
        }
      }

      void mergeNodes(Node* prevNode, Node* node) {
         for (int i = 0; i < node->size; i++) {
               prevNode->data[prevNode->size++] = node->data[i];
         }
         prevNode->next = node->next;
         node->next->prev = prevNode;
         delete node;
         nodeCount--;
      }

      void redistributeNodes(Node* prevNode, Node* node) {
         int totalItems = prevNode->size + node->size;
         int redistributeCount = totalItems / 2 - node->size;

         // Move items from prevNode to node
         for (int i = 0; i < redistributeCount; i++) {
               node->insert(prevNode->data[prevNode->size - redistributeCount + i]);
         }
         prevNode->size -= redistributeCount;
      }

         int getCapacity() { return capacity; }
         int getSize() { return size; }
         T getMin() { return data[0]; }
         T getMax() { return data[size - 1]; }

         bool insert(T item) {
            if (find(item)) return false;
            // Ensure there's space handled by caller
            data[size++] = item;
            std::sort(data, data + size);
            return true;
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
            int i = 0;
            for (; i < size; i++) {
                  if (data[i] == item) {
                     break;
                  }
            }
            if (i == size) return false; // Item not found

            for (; i < size - 1; i++) {
                  data[i] = data[i + 1];
            }
            size--;
            return true;
         }

         void display() {
            for (int i = 0; i < size; i++) {
                  cout << data[i] << " ";
            }
         }
      };

      int size;
      int nodeCount;
      int nodeCapacity;
      Node* front;
      Node* back;
};