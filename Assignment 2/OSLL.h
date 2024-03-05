/* Ordered Set Implemented in a Doubly-Linked List */
// File: OSLL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T> 
class OSLL
{
public:
   OSLL(){
      // make the front and back dummy nodes 
      front = new Node( T(), nullptr, nullptr);
      back = new Node( T(), front,nullptr);
      front->next = back;

      size = 0 ;
   }
   ~OSLL(){
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
      // inserts item into the list, if it is not already there
      // returns true if inserted, false if it was already there 
      Node * cursor = front-> next ;
      while( cursor->data < item && cursor != back ){
         cursor = cursor-> next ;
      }
      // insert a new node with item just before cursor
      // unless the node at the cursor has item already
      if( cursor -> data != item ){
	 // If the item is not here, insert a new node with it
	 //
	 // IMPLEMENT THIS
	 //
         return true ;
      }else{
	 // The item was already here 
         return false ; 
      }
   }


   bool find(T item){
      // searches for item in the list 
      // returns true if found; false otherwise 
      Node * cursor = front-> next ;
      while( cursor->data < item && cursor != back ){
         cursor = cursor-> next ;
      }
      return(  cursor->data == item);
   }


   bool remove(T item){ 
      // removed item fro the list 
      // returns false if it was not there; true if removed
      Node * cursor = front-> next ;
      while( cursor->data < item && cursor != back ){
         cursor = cursor-> next ;
      }
      if( cursor == back  || cursor->data > item ){ 
         // The item is not in the list 
         return false ; 
      }else{
	 // Delete the node with the item
	 //
	 // IMPLEMENT THIS 
	 //
         size -- ;
         return true ;
      }
   }

   T getMin(){
     // returns the minimum item in the list
     // requires: size > 0 
     return front->next->data ; 
   } 
   T getMax(){ 
      // returns the maximum item in the list 
      // requires: size > 0
      return back->prev->data ; 
   }

   void display(){
      // prints out the list contents 
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back ){
         cout << " " << cursor-> data ;
         cursor = cursor-> next ;
      }
      cout << " >" ;
   }
      
private:

   class Node{
      public: 
      Node( T data, Node* prev, Node* next ){
         // notice that the constructor argruments do most of 
         // the work of linking a new node into the list 
         this->data = data ;
         this->prev = prev ;
         this->next = next ;
      }
      Node * prev ;
      Node * next ;
      T data ;
   };

   int size ; // current number of items 
   Node * front ; 
   Node * back ;
};
