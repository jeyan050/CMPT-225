#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "entry.cpp"

using namespace std;

class QuadNode{
    public:
        Entry* node;
        
        QuadNode *prev;
        QuadNode *next;
        QuadNode *above;
        QuadNode *below;

        QuadNode(Entry* key);
};

class SkipList{
    private:
        const static int posInfinity = 100;
        const static int negInfinity = -1;

        Entry* end = new Entry(-2);

        QuadNode* topLeft;
        
        int numElements;
        int numLevels;
        
    public:
        SkipList();                     //constructor
        ~SkipList();                    //deconstructor

        int size();                     //number of elements in the skip list
        bool empty();                   //is size == 0

        void print();                   //print function

        Entry& find(int k);             //if the map M has an entry w/ key k, return it;
                                        //else, return a reference to a speical Entry end.
        Entry& greaterEntry(int k);     //find the entry w/ the lowest key that is greater than k
        Entry& lessEntry(int k);        //find the entry w/ the greatest key that is less than k   
        void put(int k, string v);      //if there is no entry w/ key k, insert entry (k,v)
                                        //and otherwise set the entry's value to v
        void erase(int k);              //if the map M has an entry w/ key k, remove it from M
                                        //Otherwise give an error.

        void changePointersInsert(QuadNode* beforeN, QuadNode* n, int currentRow); //change pointers for insert
        void changePointersErase(QuadNode* n); //change pointers for erase
        void insertNewRow();            //function to create a new row when needed
        void deleteNewRow();            //function to delete a row when needed
        QuadNode* findLocation(int k);  //find function to use for searching (closest) quadnode
        int randomize();                //for insert
};

#endif