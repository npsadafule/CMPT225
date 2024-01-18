#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

template <typename Object>
class Deque
{
  public:
    Deque()
      {
         theCapacity = 8 ;
         objects = new Object[ theCapacity ];
         theSize = 0 ;
         front = 0 ;
         back = 0 ;
      }

    ~Deque( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }

    void clear( ) // remove all contents and reset the capacity to it's initial value
    {
        delete[] objects;
        theCapacity = 8;
        objects = new Object[theCapacity];
        theSize = 0;
        front = 0;
        back = 0;
    }

    void reserve( int newCapacity ) // change the capacity to newCapacity (provided it is larger than the current size)
    {
        if (newCapacity > theSize) {
          Object* newArray = new Object[newCapacity];
          for (int i = 0; i < theSize; ++i){
              newArray[i] = objects[(front + i) % theCapacity];
          }
          delete[] objects;
          objects = newArray;
          front = 0;
          back = theSize;
          theCapacity = newCapacity;
        }
    }
    //Array like access
    Object & operator[](int index){ 
        return objects[(front + index) % theCapacity]; 
    }
    const Object & operator[](int index) const{ 
        return objects[(front + index) % theCapacity]; 
    }
    
    // Operations
    void enqueue( const Object & x )// Insert a new object at the back
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ;
        back = (back+1) % theCapacity ;
        theSize++ ;
    }

    void jump( const Object & x )// Insert a new object at the front
    {
        if (theSize == theCapacity){
          reserve(2 * theCapacity + 1);
        }
        front = (front - 1 + theCapacity) % theCapacity;
        objects[front] = x;
        theSize++;  
    }

    Object dequeue()// Remove and return the object at the front
    {
        theSize--;
        Object temp = objects[front];
        front = (front + 1) % theCapacity ;
        return temp ;
    }

    Object eject( )// Remove and return the object at the back
    {
        if (empty()){
          cerr<< "Deque empty. No objects to eject.";
          exit(1);
        }
        else{
          theSize--;
          back = (back + theCapacity - 1) % theCapacity;
          return objects[back];
        }
    }

    void display() const // print out the contents of the deque. The output should be similar to that used in the Vector and Stack classes provided.
    {
        cout<<"Size = "<<theSize<<endl;
        cout<<"< ";
        for(int i=0 ; i<theSize ; ++i){
          cout<< i <<"="<<objects[(front + i) % theCapacity]<<" , ";
        }
        cout<<">";  
    }

    void ddisplay() const // print out the contents of the objects array, and relevant variables, for debugging or verifying correctness. The output should be in the style used in Vector and Stack classes provided.
    {
        cout<<"Capacity = "<<theCapacity<<", Size = "<<theSize<<", Front = "<<front<<", Back = "<<back<<endl;
        cout<<"[ ";
        for(int i=0 ; i<theCapacity ; ++i){
          cout<< i <<"="<<objects[i]<<" , ";
        }
        cout<<"]";
    }


  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

#endif
