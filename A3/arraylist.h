#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <string>
#include <iostream>

using namespace std;

class EmptyListException{
    private:
        string msg1;

    public:
        EmptyListException(string str);    //constructor for EmptyListException
        ~EmptyListException();             //destructor for EmptyListException
};

class InvalidIteratorException{
    private:
        string msg2;

    public:
        InvalidIteratorException(string str);    //constructor for InvalidIteratorException
        ~InvalidIteratorException();             //destructor for InvalidIteratorException
};

template <typename T>
class MyArrayList{
    public:
        class Iterator;

        class Iterator{
            private:         
                MyArrayList<T>* AccessAL;
                int index; 
            public: 
                friend class MyArrayList;
                Iterator(int p, MyArrayList* x);
                T& operator*(); // gives the reference to the object at the iterator's position
                Iterator operator++(); // moves the iterator one forward in the ArrayList
                Iterator operator--(); // moves the iterator one backwards in the ArrayList
                bool operator==(Iterator& i); // compares this iterator with the iterator i. Workd even if i
                                              // is an invalid iterator
        };

        MyArrayList(int cap = 4); // constructor
        ~MyArrayList(); // destructor

        int size(); // number of elements in ArrayList
        const bool empty(); // is size = 0?

        T& operator[](int i); // returns the element at index i of the ArrayList.
                              // note that this is not index i of the underlying array.
        T& front(); // returns the element at the front of the ArrayList.
        T& back(); // returns the element at the back of the ArrayList.

        void insertFront(T& e); // insert at the front of the ArrayList.
                                // Grows underlying array if necessary.
        void insertBack(T& e); // insert at the back of the ArrayList.
                              // Grows underlying array if necessary.
        void insert(Iterator p, T& e); // insert before the iterator p. This could involve growing
                                       // the underlying array and/or copying elements forward in it.
        void removeFront(); // removes the front element of the ArrayList.
                            // throw an EmptyListException if ArrayList is empty
        void removeBack(); // removes the back element of the ArrayList.
                           // throw an EmptyListException if ArrayList is empty.
        void remove(Iterator p); // removes the element at the iterator p from the ArrayList.
                                 // may involve copying of elements. 
                                 // throw if ArrayList is empty

        Iterator begin(); // an iterator to the first element
        Iterator end(); // an iterator to the element after the last element.
    private:
        T* array;
        int capacity;
        int sizeOfAL;           
        
        //Iterator firstElm;
        int firstElm;

        //Iterator lastElm;
        int lastElm;
};

#include "arraylist.cpp"

#endif