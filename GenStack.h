//https://www.youtube.com/watch?v=I-hZkUa9mIs
//Uses in-class example for reference
//https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file


#include <iostream>
using namespace std;

template<typename dataType>
class GenStack 
{
     public:
          GenStack(); //default constructor
          GenStack(int maxSize); //overloaded constructor
          ~GenStack(); //destructor

          //functions
          void push(dataType data);   //insert
          dataType pop(); //remove
          void increaseStackSize(); //increases size of current stack

          //helper functions
          bool isFull();
          bool isEmpty();
          dataType peek();
          int getSize();

          int stackSize;  //max size of myStack
          int top;//variable to keep track of indicies representing top of our stack
               
          char *myArray; //Arrays are nice

};