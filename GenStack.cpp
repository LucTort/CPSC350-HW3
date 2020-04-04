//https://www.cprogramming.com/tutorial/templates.html
//https://stackoverflow.com/questions/2639255/return-a-null-object-if-search-result-not-found
//Christopher Chang
//https://www.tutorialspoint.com/cplusplus/cpp_templates.htm

#include "GenStack.h"

// //default constructor

template<typename dataType>
GenStack<dataType>::GenStack()
{
    myArray = new char[128];
    stackSize = 128;
    top = -1;

}

// //overloaded constructor
template<typename dataType>
GenStack<dataType>::GenStack(int maxSize)
{
    myArray = new char[maxSize];
    stackSize = maxSize;
    top = -1;
}

template<typename dataType>
GenStack<dataType>::~GenStack()
{
    delete myArray; //As reccommended by Chris Chang
}

//    _____               ____              __  _             
//   / ___/__  _______   / __/_ _____  ____/ /_(_)__  ___  ___
//  / /__/ _ \/ __/ -_) / _// // / _ \/ __/ __/ / _ \/ _ \(_-<
//  \___/\___/_/  \__/ /_/  \_,_/_//_/\__/\__/_/\___/_//_/___/
//                                                            

template<typename dataType>
void GenStack<dataType>::push(dataType data)
{
    if (this->isFull())
        {this->increaseStackSize();}

    myArray[++top] = data; //elegent code, es muy bien
}

template<typename dataType>
dataType GenStack<dataType>::pop() 
{
    //check if empty before removing
    if(this->isEmpty())
        cout << "Error: Stack is empty, cannot pop" << endl;
    else 
        return myArray[top--];  //post decrement -- decreases its value after it returns the value
}

//automaticaly allocates more space for itself
template<typename dataType>
void GenStack<dataType>::increaseStackSize() 
{
    GenStack<dataType> *newStack = new GenStack<dataType>(this->getSize() + 128);
    GenStack<dataType> *placeholderStack = new GenStack<dataType>(this->getSize());

    for (int x = 0; x < this->getSize(); ++x)
    {
        placeholderStack->push(this->pop());
    }

    for (int x = 0; x < this->getSize(); ++x)
    {
        newStack->push(placeholderStack->pop());
    }

    stackSize += 128;
    *this = *newStack;
}

template<typename dataType>
dataType GenStack<dataType>::peek()
{
    if(this->isEmpty())
        cout << "Error: Stack is empty, cannot peek" << endl;
    else
        return myArray[top];  //post decrement -- decreases its value after it returns the value
}

//     __ __    __               ____              __  _             
//    / // /__ / /__  ___ ____  / __/_ _____  ____/ /_(_)__  ___  ___
//   / _  / -_) / _ \/ -_) __/ / _// // / _ \/ __/ __/ / _ \/ _ \(_-<
//  /_//_/\__/_/ .__/\__/_/   /_/  \_,_/_//_/\__/\__/_/\___/_//_/___/
//            /_/                                                    

template<typename dataType>
bool GenStack<dataType>::isFull()
{
    return (top == stackSize - 1);
}

template<typename dataType>
bool GenStack<dataType>::isEmpty()
{
    return (top == -1);
}

template<typename dataType>
int GenStack<dataType>::getSize()
{
    return stackSize;
}