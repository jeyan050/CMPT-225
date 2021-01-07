#include <string>
#include <iostream>
#include <bits/stdtr1c++.h>
#include <time.h>

using namespace std;

#include "skiplist.h"

QuadNode::QuadNode(Entry* value){           //constructor for QuadNodes
    this->node = value;

    this->prev = NULL;
    this->next = NULL;
    this->above = NULL;
    this->below = NULL;
}

//--------------------------------------------------------------------------------//
SkipList::SkipList(){                       //constructor for SkipList
    Entry *tempBegin = new Entry(negInfinity);
    QuadNode* negInfinityNode = new QuadNode(tempBegin);
    
    Entry *tempEnd = new Entry(posInfinity);
    QuadNode* posInfinityNode = new QuadNode(tempEnd);

    negInfinityNode->next = posInfinityNode;
    posInfinityNode->prev = negInfinityNode;

    topLeft = negInfinityNode;

    numElements = 0;
    numLevels = 1;
}

SkipList::~SkipList(){                      //deconstructor for SkipList
    QuadNode* current = topLeft;
    QuadNode* temp;

    current = current->next;                //start from bottom right
    while(current->below != NULL){
        current = current->below;
    }

    while (current != topLeft){
        while(current->prev != NULL){       //delete from left to right
            temp = current->prev;
            delete[] current;
            current = temp;
        }

        if(current != topLeft){ 
            temp = current->above;          //delete negInfinity in that row
            delete[] current;
            current = temp;

            while (current->prev != NULL){  //move back to far right in set
                current = current->prev;
            }
        }
    }
    delete topLeft;
}

int SkipList::size(){                           //size of Skiplist (number of elements)
    return numElements;
}

bool SkipList::empty(){                         //if SkipList is empty
    return numElements==0;
}

//----------------------------------------------------------//
int SkipList::randomize(){                      //randomise function to determine height of certain node
    int count = 0;
    int b;
    while (count >= 0){
        b = rand()%2;
        if(b == 0){
            break;
        }
        count++;
    }
    return count;
}

QuadNode* SkipList::findLocation(int k){        //simular to find but returns a QuadNode
    QuadNode* current = topLeft;

    QuadNode* checkNextNode = current->next;
    int checkNextKey = checkNextNode->node->getKey();

    int currentLevel = numLevels-1;

    while(currentLevel < 0){
        if(current->node->getKey() == k){
            break;
        }
        
        checkNextNode = current->next;
        checkNextKey = checkNextNode->node->getKey();

        if(checkNextKey < k){
            current = checkNextNode;
        } else if (checkNextKey > k && current->below == NULL){
            break;
        } else {
            current = current->below;
        }
    }
    return current;
}
//----------------------------------------------------------//

Entry& SkipList::find(int k){                   //if the map M has an entry w/ key k, return it;
                                                //else, return a reference to a speical Entry end.
    QuadNode* current = topLeft;

    Entry* notFoundIndicator = topLeft->node;

    int currentKey = current->node->getKey();
    QuadNode* checkNextNode = current->next;
    int checkNextKey = checkNextNode->node->getKey();
    
    while(currentKey != k){
        if(current->node->getKey() == k){
            return *(current->node);
        }
        
        checkNextNode = current->next;
        checkNextKey = checkNextNode->node->getKey();

        if(checkNextKey < k){
            current = checkNextNode;
        } else if (checkNextKey > k && current->below == NULL){
            break;
        } else {
            current = current->below;
        }
    }
    return *end;
}

Entry& SkipList::greaterEntry(int k){           //find the entry w/ the lowest key that is greater than k
    QuadNode* result = findLocation(k);
    return *(result->next->node);
}

Entry& SkipList::lessEntry(int k){              //find the entry w/ the greatest key that is lower than k
    QuadNode* result = findLocation(k);
    return *(result->next->node);
}

//----------------------------------------------------//
void SkipList::changePointersInsert(QuadNode* beforeN, QuadNode* n, int currentRow){    //change pointers for inserting node n

    if(currentRow == numLevels-2){      //if on 2nd top row
        n->next = beforeN->next;
        n->prev = beforeN;
        beforeN->next->prev = n;
        
        beforeN->next = n;                  //change pointers of beforeN to be at n

    } else {                           //if on any other row
        n->next = beforeN->next;
        n->prev = beforeN;
        beforeN->next->prev = n;

        if (beforeN->above != NULL){
            n->above = beforeN->above->next;    //set up pointers for above
            beforeN->above->next->below = n;    //(dont need to do below, as it will be handled)
        } else {
            QuadNode* temp = beforeN;
            while (temp->prev != NULL){
                temp = temp->prev;
            }
            temp = temp->above;
            while (temp->node->getKey() != n->node->getKey()){
                temp = temp->next;
            }
            n->above = temp;
            temp->below = n;
        }

        beforeN->next = n;                  //change pointers of beforeN and afterN to be at n
    }
}

void SkipList::insertNewRow(){              //creates a new row for SkipList
    QuadNode* temp = topLeft;
    
    Entry *newNegInfinity = new Entry(negInfinity);
    QuadNode* newTopLeft = new QuadNode(newNegInfinity);
    
    Entry *newPosInfinity = new Entry(posInfinity);
    QuadNode* newTopRight = new QuadNode(newPosInfinity);

    QuadNode* oldTopRight = temp;
    while (oldTopRight->next != NULL){      //find the positive Infinity on top row
        oldTopRight = oldTopRight->next;
    }

    temp->above = newTopLeft;
    newTopLeft->below = temp;

    oldTopRight->above = newTopRight;
    newTopRight->below = oldTopRight;

    topLeft = newTopLeft;
    topLeft->next = newTopRight;

    numLevels++;
}
//----------------------------------------------------//

void SkipList::put(int k, string v){            //if there is no entry w/ key k, insert entry (k,v)
                                                //and otherwise set the entry's value to v
    QuadNode* result = findLocation(k);

    Entry* newEntry = new Entry(k, v);

    if(result->node->getKey() == k){            //if there an entry with same key
        result->node = newEntry;
        while(result->above != NULL){
            result = result->above;
            result->node = newEntry;
        }
    } else {                                    //if not
        int whichLevels = randomize();
        QuadNode* insertNewNode = new QuadNode(newEntry);

        if (whichLevels >= numLevels-1){              //if i is >= than number of levels
            
            for(int i = numLevels-1; i < whichLevels; i++){
                insertNewRow();
            }

            insertNewRow();                             //for row without any nodes
            int keyValue = insertNewNode->node->getKey();
        
            //start at topleft and it shouldn't have a copy of it
            QuadNode* current = topLeft;
            current = current->below;
            
            //2nd set has to have one copy of new QuadNode
            int currentLevel = numLevels-2;
            changePointersInsert(current, insertNewNode, currentLevel);
            current = current->below;
            currentLevel--;

            //goes through rest, which could have nodes in between
            while (currentLevel >= 0){ 
                if(current->below == NULL && insertNewNode->node->getKey() < current->next->node->getKey()){
                    changePointersInsert(current, insertNewNode,currentLevel); 
                    break;
                }                
                if(insertNewNode->node->getKey() > current->next->node->getKey()){
                    current = current->next;
                } else {
                    changePointersInsert(current, insertNewNode,currentLevel);
                    current = current->below;
                    currentLevel--;
                }
            }

        } else {                                    //if i is less than height
            QuadNode* current = topLeft;
            int currentLevel = numLevels-1;
            
            for(int i = numLevels-1; i > whichLevels; i--){     //move down until reach right height
                current = current->below;
                currentLevel--;
            }

            int keyValue = insertNewNode->node->getKey();

            //goes through rest, which could have nodes in between
            while (currentLevel > -1){ 
                if(current->below == NULL && insertNewNode->node->getKey() < current->next->node->getKey()){
                    changePointersInsert(current, insertNewNode,currentLevel);
                    break;
                }                
                if(insertNewNode->node->getKey() > current->next->node->getKey()){
                    current = current->next;
                } else {
                    changePointersInsert(current, insertNewNode,currentLevel);
                    current = current->below;
                    currentLevel--;
                }
            } 
        }
    }
    numElements++;
    return;
}

//----------------------------------------------------//
void SkipList::changePointersErase(QuadNode* n){    //change pointers for erase
    QuadNode* afterN = n->next;
    QuadNode* beforeN = n->prev;

    if(beforeN->node->getKey() == -1){ //if on 2nd top row
        beforeN->next = afterN;
        afterN->prev = beforeN;

    } else if(n->below == NULL){       //if on very bottom row
        beforeN->next = afterN;
        afterN->prev = beforeN;

    } else {                           //if on any other row
        beforeN->next = afterN;
        afterN->prev = beforeN;
    }
}

void SkipList::deleteNewRow(){                      //function to delete a row when needed
    QuadNode* newTopLeft = topLeft->below;
    QuadNode* newTopRight = topLeft->next->below;

    QuadNode* oldTopRight = topLeft->next;

    newTopRight->above = NULL;
    newTopLeft->above = NULL;

    delete oldTopRight;
    delete topLeft;

    topLeft = newTopLeft;

    numLevels--;
}
//----------------------------------------------------//

void SkipList::erase(int k){                        //if the map M has an entry w/ key k, remove it from M
                                                    //Otherwise give an error.
    QuadNode* result = findLocation(k);

    if(result->node->getKey() != k){        //if there was no quadnode with that same key
        cout << "no node with that key" << endl;
        return;
    } else {                                //else
        bool isHighest = false;
        QuadNode* checkHighest = topLeft;
        while(checkHighest->next != NULL){
            if (checkHighest->node->getKey() == k){
                isHighest = true;
            }
        }
        if (isHighest == true){
            QuadNode* current = result;

            while(current != topLeft){
                QuadNode* temp = current->above;

                if(temp != NULL){   //bottom or middle
                    changePointersErase(current);
                    delete current;
                    current = temp;
                } else {            //last top row
                    temp = current->prev->above;    //to end while loop
                    changePointersErase(current);
                    delete current;
                    current = temp;
                }
            }
            deleteNewRow();

        } else {
            QuadNode* current = result;

            while(current != topLeft){
                QuadNode* nextDelete = current->above;

                if(nextDelete != NULL){   //bottom or middle
                    changePointersErase(current);
                    delete current;
                    current = nextDelete;
                } else {            //last top row
                    nextDelete = current->prev->above;    //to end while loop
                    changePointersErase(current);
                    delete current;
                    current = nextDelete;
                }
            }
        }
    }
    return;
}

void SkipList::print(){                 //print function
    //print first line
    cout << "-inf";
    for(int i = 0; i < numElements; i++){
        cout << "--" << "--";
    }
    cout << "--inf" << endl;

    //print rest of lines
    QuadNode* current = topLeft;
    int currentLevel = 1;

    for(int i = numLevels-2; i >= 0; i--){
        // negative infinity        
        current = topLeft;

        for (int i = currentLevel; i < 0; i--){
            current = current->below;
        }

        cout << "-inf";

        // nodes in between
        while(current->next->next != NULL){             //if it connects with a node with a value (doesnt include
                                                        //positive infinity)
            current = current->next;                    
            QuadNode* howFar = current;
            int numElementsBefore = 0;

            while(howFar->below != NULL){               //goes to the very bottom to row 0
                howFar = howFar->below;
            }
            while(howFar->prev != NULL){  //goes to the very left, counting how many elements before it
                if(howFar->prev->above != NULL){            //if theres a node that has multiple levels, it check if
                                                            //theres one thats also on the same level
                    QuadNode* checkIfSameLvl = howFar;
                    int checkIfSameHeight;
                    for(int e = 0; e < i; e++){             //checks if it on the same level
                        if(checkIfSameLvl->above == NULL){
                            break;
                        }
                        checkIfSameHeight++;
                    }
                    if(checkIfSameHeight == i){
                        break;
                    }
                }
                numElementsBefore++;
                howFar = howFar->prev;
            }

            for(int i = 0; i < numElementsBefore; i++){ //prints spaces in between
                cout << "--" << "--";
            }
            if(current->node->getKey() < 10)
                cout << "--" << "0" << current->node->getKey();    //prints value of key
            else 
                cout << "--" << current->node->getKey(); 
        }
        //positive infinity
        int howFarForInfinity = 0;
        QuadNode* temp = current;
        while (temp->below != NULL){
            temp = temp->below;
        }
        while (temp->prev != NULL){
            temp = temp->prev;
            howFarForInfinity++;
        }
        for(int r = numElements-howFarForInfinity; r > 0; r--){
            cout << "--" << "--";
        }
        cout << "--" << "inf" << endl;
    }
}