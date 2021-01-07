#include <string>
#include <iostream>

#include "arraylist.h"

using namespace std;

EmptyListException::EmptyListException(string str){  // constructor for EmptyStackException
    msg1 = str;
}
EmptyListException::~EmptyListException(){}    // Destructor EmptyStackException 

//----------------------------------------------------//

InvalidIteratorException::InvalidIteratorException(string str){  // constructor for InvalidIteratorException
    msg2 = str;
}
InvalidIteratorException::~InvalidIteratorException(){}    // Destructor InvalidIteratorException 

//----------------------------------------------------//

template <typename T>
MyArrayList<T>::Iterator::Iterator(int p, MyArrayList* x){ // Constructor for Iterator
    index = p;
    AccessAL = x;
}

template <typename T>
T& MyArrayList<T>::Iterator::operator*(){ // gives the reference to the object at the iterator’s position
    return AccessAL->array[index];
}

template <typename T>
typename MyArrayList<T>::Iterator MyArrayList<T>::Iterator::operator++(){ // moves the iterator one forward in the ArrayList
    if (index == (AccessAL->capacity-1)){
        index = 0;
        return *this;
    } else {
        index++;
        return *this;
    }
}

template <typename T>
typename MyArrayList<T>::Iterator MyArrayList<T>::Iterator::operator--(){ // moves the iterator one backwards in the ArrayList
    if (index == 0){
        index = AccessAL->capacity- 1;
        return *this;
    } else {
        index--;
        return *this; 
    }
}


template <typename T>
bool MyArrayList<T>::Iterator::operator==(Iterator& i){ // compares this iterator with the iterator i.
    return index == i.index;
}


//----------------------------------------------------//

template <typename T>
MyArrayList<T>::MyArrayList(int cap){ // constructor for Arraylist
    array = new T[cap];
    sizeOfAL = 0;
    capacity = cap;

    firstElm = 0;
    lastElm = 0;

}

template <typename T>
MyArrayList<T>::~MyArrayList(){ // deconstructor for Arraylist
    delete[] array;
}

template <typename T>
int MyArrayList<T>::size(){ // number of elements in ArrayList
    return sizeOfAL;
}

template <typename T>
const bool MyArrayList<T>::empty(){ // check if ArrayList is empty
    return sizeOfAL == 0;
}

template <typename T>
T& MyArrayList<T>::operator[](int i){ // returns the element at index i of the ArrayList
    if (firstElm+i > capacity){
        return array[(firstElm+i)-capacity-1];
    } else {
        return array[firstElm+i];
    }
}

template <typename T>
T& MyArrayList<T>::front(){ // returns the element at the front of the ArrayList
    if(empty()){
        throw EmptyListException("Can't Check Front of Empty ArrayList");
    }
    return array[firstElm];
}

template <typename T>
T& MyArrayList<T>::back(){ // returns the element at the back of the ArrayList.
    if(empty()){
        throw EmptyListException("Can't Check Back of Empty ArrayList");
    }
    return array[lastElm];
}

template <typename T>
void MyArrayList<T>::insertFront(T& e){ // insert at the front of the ArrayList & grows it if necessary
    if (size() == capacity){  // Checks if array is already full
        int oldCap = capacity;
        int newCap = oldCap * 2;
        T *biggerA = new T[newCap]; // Creates new array with x2 the size

        int locatedLastElm = 0;
        if (firstElm > lastElm){
            for (int i = firstElm; i < capacity; i++){
                biggerA[i] = array[i];
                locatedLastElm++;
            }
            for (int a = 0; a <= lastElm; a++){
                biggerA[a] = array[a];
                locatedLastElm++;
            }
        } else {
            for (int i = firstElm; i <= lastElm; i++){
                biggerA[i] = array[i];
                locatedLastElm++;
            }            
        }
        delete[] array; // Delete old array and assigns the new array to it
        array = biggerA;
        capacity = newCap;
        firstElm = array[0];
        lastElm = array[locatedLastElm-1];
    }
    insert(begin(), e); // calls function insert to do the insert at front
}
template <typename T>
void MyArrayList<T>::insertBack(T& e){ // insert at the back of the ArrayList & grows it if necessary
    if (size() == capacity){  // Checks if array is already full
        int oldCap = capacity;
        int newCap = oldCap * 2;
        T *biggerA = new T[newCap]; // Creates new array with x2 the size

        int locatedLastElm = 0;
        int placement = 0;
        if (firstElm > lastElm){
            for (int i = firstElm; i < capacity; i++){
                biggerA[placement] = array[i];
                placement++;
                locatedLastElm++;
            }
            for (int a = 0; a <= lastElm; a++){
                biggerA[placement] = array[a];
                placement++;
                locatedLastElm++;
            }
        } else {
            for (int i = firstElm; i <= lastElm; i++){
                biggerA[placement] = array[i];
                placement++;
                locatedLastElm++;
            }            
        }
        delete[] array; // Delete old array and assigns the new array to it
        array = biggerA;
        capacity = newCap;
        firstElm = 0;
        lastElm= locatedLastElm-1;
    }
        
    insert(end(), e); // calls function insert to do the insert at back
}

template <typename T>
void MyArrayList<T>::insert(Iterator p, T& e){ // insert before the iterator p. 
    if (size() == capacity){  // Checks if array is already full
        int oldCap = capacity;
        int newCap = oldCap * 2;
        T *biggerA = new T[newCap]; // Creates new array with x2 the size

        int locatedLastElm = 0;
        int placement = 0;
        if (firstElm > lastElm){
            for (int i = firstElm; i < capacity; i++){
                biggerA[placement] = array[i];
                placement++;
                locatedLastElm++;
            }
            for (int a = 0; a <= lastElm; a++){
                biggerA[placement] = array[a];
                placement++;
                locatedLastElm++;
            }
        } else {
            for (int i = firstElm; i <= lastElm; i++){
                biggerA[placement] = array[i];
                placement++;
                locatedLastElm++;
            }            
        }
        delete[] array; // Delete old array and assigns the new array to it
        array = biggerA;
        capacity = newCap;
        firstElm = 0;
        lastElm= locatedLastElm-1;
    }
    int pos = p.index;
    if (end() == p){ // For insertBack Function
        if (size() == 0){
            if (pos == 0){
                array[capacity-1] = e;
                firstElm = capacity-1;
                lastElm = capacity-1;
            } else {
                array[pos-1] = e;
                firstElm = pos-1;
                lastElm = pos-1;
            }
            sizeOfAL++;
            return;
        } else {
            if (pos == capacity-1){
                array[0] = e;
                lastElm = 0;
            } else {
                array[pos+1] = e;
                lastElm = pos+1;
            } 
            sizeOfAL++;
            return;
        }
    } else if (begin() == p){ // For insertFront Function
        if (size() == 0){
            if (pos == 0){
                array[capacity-1] = e;
                firstElm = capacity-1;
                lastElm = capacity-1;
            } else {
                array[pos-1] = e;
                firstElm = pos-1;
                lastElm = pos-1;
            }
            sizeOfAL++;
            return;
        } else {
            if (pos == 0){
                array[capacity-1] = e;
                lastElm = capacity-1;
            } else {
                array[pos-1] = e;
                lastElm = pos-1;
            } 
            sizeOfAL++;
            return;
        }  
    } else { // For insert Function
        if (size() == 0){
            if (pos == 0){
                array[capacity-1] = e;
                firstElm = capacity-1;
                lastElm = capacity-1;
            } else {
                array[pos-1] = e;
                firstElm = pos-1;
                lastElm = pos-1;
            }
            sizeOfAL++;
            return;
        } else if (firstElm > lastElm){
            for (int i = end().index; i > 0; i--){
                array[i] = array[i-1];
            }
            for (int a = capacity-1; a > p.index; a--){
                if (a = capacity-1){
                    array[a] = array[0];
                    continue;
                }
                array[a] = array[a-1];
            }
            array[p.index-1] = e;
            lastElm++;
        } else {
            for (int i = end().index; i > p.index; i++){
                if (i == capacity-1){
                    array[0] = array[capacity-1];
                    continue;
                }
                array[i] = array[i-1];
            }
            array[p.index-1] = e;
            if (lastElm == capacity-1){
                lastElm = 0;
            } else {
                lastElm++;
            }
        }
        sizeOfAL++;
        return;
    }
}

template <typename T>
void MyArrayList<T>::removeFront(){ // removes the front element of the ArrayList
    if (empty()){
        throw EmptyListException("Can't remove front if empty");
    }
    remove(begin()); // calls function remove to do the remove at front
}

template <typename T>
void MyArrayList<T>::removeBack(){ // removes the back element of the ArrayList.
    if (empty()){
        throw EmptyListException("Can't remove front if empty");
    }
    remove(end()); // calls function remove to do the remove at back
}

template <typename T>
void MyArrayList<T>::remove(Iterator p){ // removes the element at the iterator p from the ArrayList.
    if (empty()){
        throw EmptyListException("Can't remove front if empty");
    }
    if (begin() == p){ // For removeFront
        if (p.index == capacity-1){  
            firstElm = 0;         
        } else {
            firstElm++;
        }
    } else if (lastElm == p.index){ // For removeBack
        if (lastElm == 0){
            lastElm = capacity-1;
        } else {
            lastElm--;
        }
    } else { // For remove
        if (firstElm > lastElm){
            for (int i = p.index; i < capacity; i++){
                if (i == capacity-1){
                    array[i] = array[0];
                }
                array[i] = array[i+1];
                continue;
            }
            for (int a = 0; a < lastElm; a++){
                array[a] = array[a+1];
            }
            if (lastElm == 0){
                lastElm = capacity-1;
            } else {
                lastElm--;
            }
        } else {
            for (int i = p.index; i < lastElm; i++){
                array[i] = array[i+1];
            }
            if (lastElm == 0){
                lastElm = capacity-1;
            } else {
                lastElm--;
            }
        }
    }
    sizeOfAL--;
    return;
}

template <typename T>
typename MyArrayList<T>::Iterator MyArrayList<T>::begin(){  // an iterator to the first element
    MyArrayList<T>::Iterator beginning(firstElm, this);
    return beginning;
}

template <typename T>
typename MyArrayList<T>::Iterator MyArrayList<T>::end(){  // an iterator to the element after the last element.
    MyArrayList<T>::Iterator ending(lastElm, this);
    return ending;
}
