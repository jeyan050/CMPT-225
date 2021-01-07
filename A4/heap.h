#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <string>
#include <sstream>

#include "entry.cpp"

/*
    Has to be a Max Heap
        - Highest Value is the Root
        - Lowest Values are the leaves
*/

class Heap{ 
    private:
        Entry *array;
        int sizeOfHeap;
        int capacity; 

        int leftChild(int index);               //left child
        int rightChild(int index);              //right child
        int parent(int index);                  //parent of entry
        void swapEntryInfo(Entry *x, Entry *y); //swaps entry's information with another in array

    public:
        Heap(int cap = 10);                     //constructor
        ~Heap();                                //deconstructor
        int size();                             //number of elements in Heap
        bool empty();                           //is size == 0
        Entry removeMax();                      //returns the maximum entry in the heap, and deletes it
        void insert(Entry e);                   //inserts the entry e into the heap
        void make(Entry entries[], int n);      //does the linear bottom-up makeHeap operation
                                                //to make the heap have all of the n entries in the
                                                //array. Throws away anything already in the heap

        Entry* heapSort();                      //sort an array of entries using a Heap
        void increaseSize();                    //increase size if at capacity
        void downHeap(int index);               //remove and replace root node w/ last node and restores heap-order property
        void upHeap(int index);                 //inserts new entry into heap and restores heap-order property
};

#endif