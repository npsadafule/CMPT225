/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T, int initNodeCapacity = 10 > 
class OSULL
{
public:
   OSULL(){

      // set the node capacity  
      nodeCapacity = initNodeCapacity ;

      // make the front and back dummy nodes 
      front = new Node( nullptr, nullptr, nodeCapacity );
      back = new Node( front, nullptr, nodeCapacity );
      front->next = back;

      size = 0 ;
      nodeCount = 0 ; 
   }
   ~OSULL(){
      Node * cursor = front ;
      while( cursor != nullptr ){
         Node * current = cursor ;
         cursor = cursor-> next ;
         delete  current ;
      }
   }
   bool isEmpty(){ return size==0 ;}
   int get_size(){ return size ;}

   bool insert(T item){
      Node * cursor = front->next;
      while(cursor != back){
         if(cursor->size < cursor->capacity){
            // There is room in this node
            int i = 0;
            while(i < cursor->size && cursor->data[i] < item){
               i++;
            }
            if(i < cursor->size && cursor->data[i] == item){
               // Item is already in the list
               return false;
            }
            // Shift items to make room for the new item
            for(int j = cursor->size; j > i; j--){
               cursor->data[j] = cursor->data[j-1];
            }
            cursor->data[i] = item;
            cursor->size++;
            size++;
            return true;
         }
         cursor = cursor->next;
      }
      // If we reach here, all nodes are full. We need to create a new node.
      Node * newNode = new Node(back->prev, back, nodeCapacity);
      back->prev->next = newNode;
      back->prev = newNode;
      newNode->data[0] = item;
      newNode->size = 1;
      size++;
      nodeCount++;
      return true;
   }

   bool find(T item){ 
      Node * cursor = front->next;
      while(cursor != back){
         for(int i = 0; i < cursor->size; i++){
            if(cursor->data[i] == item){
               return true;
            }
         }
         cursor = cursor->next;
      }
      return false;
   }

      bool remove(T item){
      Node * cursor = front->next;
      while(cursor != back){
         for(int i = 0; i < cursor->size; i++){
            if(cursor->data[i] == item){
               // Shift items to remove the item
               for(int j = i; j < cursor->size-1; j++){
                  cursor->data[j] = cursor->data[j+1];
               }
               cursor->size--;
               size--;
               // If the node is too empty and it's not the only node
               if(cursor->size < cursor->capacity / 2 && nodeCount > 1){
                  // Merge nodes or remove node
                  if(cursor->next != back && cursor->size + cursor->next->size <= cursor->capacity){
                     // Merge with next node
                     for(int k = 0; k < cursor->next->size; k++){
                        cursor->data[cursor->size+k] = cursor->next->data[k];
                     }
                     cursor->size += cursor->next->size;
                     Node * toDelete = cursor->next;
                     cursor->next = cursor->next->next;
                     cursor->next->prev = cursor;
                     delete toDelete;
                     nodeCount--;
                  }else if(cursor->prev != front && cursor->size + cursor->prev->size <= cursor->capacity){
                     // Merge with previous node
                     for(int k = cursor->prev->size; k < cursor->prev->size + cursor->size; k++){
                        cursor->prev->data[k] = cursor->data[k - cursor->prev->size];
                     }
                     cursor->prev->size += cursor->size;
                     Node * toDelete = cursor;
                     cursor->prev->next = cursor->next;
                     cursor->next->prev = cursor->prev;
                     delete toDelete;
                     nodeCount--;
                  }
               }
               return true;
            }
         }
         cursor = cursor->next;
      }
      return false;
   }

   T getMin() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot get minimum from an empty list");
    }
    return front->next->getMin();
}

   T getMax() {
      if (isEmpty()) {
         throw std::runtime_error("Cannot get maximum from an empty list");
      }
      Node * cursor = front->next;
      while(cursor->next != back){
         cursor = cursor->next;
      }
      return cursor->getMax();
   }

   void display(){
      Node * cursor = front->next;
      cout << "<" ;
      while( cursor != back ){
         for(int i = 0; i < cursor->size; i++){
            cout << cursor->data[i] << " ";
         }
         cursor = cursor->next;
      }
      cout << ">" << endl;
   }
      
private:

   class Node{
      public: 
      Node( Node* prev, Node* next, int capacity ){
         // notice that we can use the constructor arguments to 
         // do most o the work of inserting a new node into the list 
         this->prev = prev ;
         this->next = next ;
         this->capacity = capacity ;
         data = new T[capacity] ;
         size = 0 ;
      }
      Node * prev ; // pointer to the next node 
      Node * next ; // pointer to the previous nodes 
      int capacity ; // capacity of this node 
      T * data ; // array of data items in this node 
      int size ; // current number of items in this node 
      int getCapacity(){// return the capacity of this node 
         return capacity; 
      }
      int getSize(){// return the number of items in this node
         return size; 
      }
      T getMin(){// return the smallest item in this node
         // requires: this->size not 0 
         return data[0] ; 
      }
      T getMax(){// return the largest item in this node 
         // requires: this->size not 0 
         return data[size-1] ; 
      }
      bool insert(T item){
         if(size == capacity){
            // Node is full
            return false;
         }
         int i = 0;
         while(i < size && data[i] < item){
            i++;
         }
         if(i < size && data[i] == item){
            // Item is already in the list
            return false;
         }
         // Shift items to make room for the new item
         for(int j = size; j > i; j--){
            data[j] = data[j-1];
         }
         data[i] = item;
         size++;
         return true;
      }

      bool find(T item){
         for(int i = 0; i < size; i++){
            if(data[i] == item){
               return true;
            }
         }
         return false;
      }

      bool remove(T item){
         for(int i = 0; i < size; i++){
            if(data[i] == item){
               // Shift items to remove the item
               for(int j = i; j < size-1; j++){
                  data[j] = data[j+1];
               }
               size--;
               return true;
            }
         }
         return false;
      }

      void display(){
         for(int i = 0; i < size; i++){
            cout << data[i] << " ";
         }
      }
   };

   int size ; // current number of items 
   int nodeCount ; // current number of nodes 
   int nodeCapacity ; // capacity to assign to new nodes 
   Node * front ; // pointer to front dummy node 
   Node * back ;  // pointer to back dummy node 
};