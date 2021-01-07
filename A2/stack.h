#ifndef _STACK_H_
#define _STACK_H_

using namespace std;

class EmptyStackException{
    private:
        string msg;

    public:
        EmptyStackException(string str);    //constructor for EmptyStackException
        ~EmptyStackException();             //destructor for EmptyStackException
};

template <typename T>
class Stack{
    private:
        T* newArray;    //array
        int cap;        //the capacity of array
        int t;          //number of elements in array
    
    public:                    
        Stack(int c = 4);              //constructor for stack
        ~Stack();                      //destructor

        const bool empty();            //returns true if the stack is empty
        const T& pop();                //removes and removes the top of the stack
        int size();                    //returns the number of elements in the stack                 
        void push(const T& e);         //pushes the arguement onto the stack, and increases
        int capacity();                //returns the current capacity of the stack
               
};

#include "stack.cpp"

#endif