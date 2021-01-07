#include <string>
#include <iostream>

#include "heap.h"

using namespace std;

Heap::Heap(int cap){                        //constructor           
    array = new Entry[cap];
    capacity = cap;
    sizeOfHeap = 0;
}

Heap::~Heap(){                              //deconstructor
    delete[] array;
}

int Heap::size(){                           //prints our size of heap
    return sizeOfHeap;
}

bool Heap::empty(){                         //checks if heap is empty
    return sizeOfHeap == 0;
}

int Heap::leftChild(int index){             //finds and returns left child
    return 2*index+1;
}

int Heap::rightChild(int index){            //finds and returns right child
    return 2*index+2;
}

int Heap::parent(int index){                //finds and returns parent
    if(index <= 0){
        return -1;
    }
    return (index-1)/2;
}

void Heap::increaseSize(){                  //increase size of array if at full capacity
    int oldCap = capacity;
    int newCap = capacity*2;
    Entry* newArr = new Entry[newCap];
    for (int i = 0; i < oldCap; i++){
        newArr[i] = array[i];
    }
    delete[] array;
    array = newArr;
    capacity = newCap;
}

void Heap::swapEntryInfo(Entry* x, Entry* y){//swaps entry's information with another in array
    Entry temp = *x;
    *x = *y;
    *y = temp;
}

void Heap::downHeap(int index){              //remove and replace root node w/ last node and restores heap-order property
    if(empty() || index < 0){
        return;
    }
    while (index < sizeOfHeap){
        int leftChildIndex = leftChild(index);      //finds child entries using index
        int rightChildIndex = rightChild(index);
        int largest = 0;
        if(leftChildIndex < sizeOfHeap && rightChildIndex < sizeOfHeap){    //if theres a left and right child entry
            if(array[index].getKey() >= array[leftChildIndex].getKey() && array[index].getKey() >= array[rightChildIndex].getKey()){
                largest = index;
            } else if (array[leftChildIndex].getKey() > array[index].getKey() && array[leftChildIndex].getKey() > array[rightChildIndex].getKey()){
                largest = leftChildIndex;
            } else {
                largest = rightChildIndex;
            }
        } else if (leftChildIndex < sizeOfHeap){    //if theres a only a left child entry
            if(array[index].getKey() >= array[leftChildIndex].getKey()){
                largest = index;
            } else {
                largest = leftChildIndex;
            }
        } else {
            return;
        }
        if (largest == index){  //if its the largest value than childs
            return;
        }
        swapEntryInfo(&array[index], &array[largest]);
        index = largest;
    }
}

void Heap::upHeap(int index){                //inserts new entry into heap and restores heap-order property
    if(index >= sizeOfHeap || index <= 0){
        return;
    }
    while (index > 0){
        int parentIndex = parent(index);    //finds parent entry
        int smallest = 0;
        if (array[index].getKey() < array[parentIndex].getKey()){ 
            smallest = index;
        } else {
            smallest = parentIndex;
        }
        if(smallest == index){
            return;
        }
        swapEntryInfo(&array[index], &array[parentIndex]);
        index = parentIndex;
    }
}

Entry Heap::removeMax(){                      //returns the maximum entry in the heap, and deletes it
    Entry temp = array[1];
    sizeOfHeap--;
    downHeap(1);
    return temp;
}

void Heap::insert(Entry e){                   //inserts the entry e into the heap
    if(size() == capacity){
        increaseSize();
    }
    array[sizeOfHeap] = e;
    sizeOfHeap++;
    upHeap(sizeOfHeap-1);
}

void Heap::make(Entry entries[],int n){       //does the linear bottom-up makeHeap operation to make the heap have all of the n entries in the array. Throws away anything already in the heap
    for(int i = 0; i<n; i++){
        if(size() == capacity){
            increaseSize();
        }
        array[i] = entries[i];
    }
    sizeOfHeap = n;
    for (int i = n-1; i >= 0; i--){
        downHeap(i);
    }
}

Entry* Heap::heapSort(){                      //sort an array of entries using a Heap
    for(int i = sizeOfHeap-1; i > 0; i--){
        swapEntryInfo(&array[0], &array[i]);
        sizeOfHeap--;
        downHeap(0);
    }
    return array;
}