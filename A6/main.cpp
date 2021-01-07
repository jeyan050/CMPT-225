#include <string>
#include <iostream>

#include "avl.cpp"

using namespace std;

int main(){

    cout << "_________________________Test#1_________________________" << endl;

    AVLTree* test1 = new AVLTree(4);    //constructing AVL Tree, and input 4 in it

    cout << "Putting 7 elements...." << endl;
    
    test1->put(1);      //inputs 7 nodes
    test1->put(2);
    test1->put(4);
    test1->put(5);
    test1->put(6);
    test1->put(7);
    cout << endl;

    cout << "Result: " << endl; 
    test1->print(test1->getRoot()); 
    cout << endl;

    cout << "Erasing Node with key 6...." << endl;
    test1->erase(6);
    cout << endl;

    cout << "Result: " << endl;
    test1->print(test1->getRoot());
    cout << endl;

    cout << "Find Node within AVLTree: ";
    if (test1->find(2)->key == test1->getEnd()->key)
        cout << "END" << endl;
    else
        cout << test1->find(2)->key << endl;

    cout << "Find Node not within AVLTree: ";
    if (test1->find(9)->key == test1->getEnd()->key)
        cout << "END" << endl;
    else
        cout << test1->find(9)->key << endl;
    
    cout << endl;

//----------------------------------------------------------------------------------------------------------//

    cout << "_________________________Test#2_________________________" << endl;

    AVLTree* test2 = new AVLTree(7);    //constructing AVL Tree, and input 7 in it

    cout << "Putting 15 elements...." << endl;

    for (int i = 1; i < 16; i++){   //inputs numbers 1 to 15, excluding 7 since its already input in (so total is 15 elements)
        if (i == 7){
            continue;
        } else {
            test2->put(i);
        }
    }

    cout << endl;
    
    cout << "Result:" << endl;
    test2->print(test2->getRoot());
    cout << endl;

    cout << "Erasing Node with key 6...." << endl;
    test2->erase(6);
    cout << "Erasing Node with key 14...." << endl;
    test2->erase(14);
    cout << "Erasing Node with key 1...." << endl;
    test2->erase(1);
    cout << "Erasing Node with key 4...." << endl;
    test2->erase(4);
    cout << "Erasing Node with key 9...." << endl;
    test2->erase(9);

    cout << endl;

    cout << "Result: " << endl;
    test2->print(test2->getRoot());
}