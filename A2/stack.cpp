#include <string>
#include <iostream>

#include "stack.h"


EmptyStackException::EmptyStackException(string str){  // constructor for EmptyStackException
    msg = str;
}
EmptyStackException::~EmptyStackException(){    //Destructor EmptyStackException
    
}

template <typename T>
Stack<T>::Stack(int c){                  //constructor for stack
    newArray = new T[c];
    cap = c;
    t =(-1);
}

template <typename T>
Stack<T>::~Stack(){                      //destructor
    delete[] newArray;
}

template <typename T>
const bool Stack<T>::empty(){             //returns true if the stack is empty
    return t<0;
}

template <typename T>
const T& Stack<T>::pop(){                //removes and removes the top of the stack
    cout << "Popping element: " << newArray[t] << endl;
    if (empty()){
        throw EmptyStackException("Can't Pop");
    }
    t--;
    return newArray[t+1];
}

template <typename T>
int Stack<T>::size(){                     //returns the number of elements in the stack
    return t+1;
}

template <typename T>                            
void Stack<T>::push(const T& e){                //pushes the arguement onto the stack, and increases
    cout << "Push : "<< e << "..." << endl;
    if (size() == capacity()){         //array size if array is already at capacity
        int c = capacity();
        int newCap = c * 2;
        T *biggerA = new T[newCap];
        for (int i = 0; i < capacity(); i++){
            biggerA[i] = newArray[i];
        }
        delete[] newArray;
        newArray = biggerA;
        cap = newCap;
    }
    t++;
    newArray[t] = e;
}

template <typename T>
int Stack<T>::capacity(){                 //returns the current capacity of the stack
    return cap;
}
