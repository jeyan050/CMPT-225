#ifndef _AVL_H_
#define _AVL_H_

#include <string>
#include <iostream>

using namespace std;

class Node{
    public:
        int key;                //key value
        int height;             //height of node
        Node* leftChild;        //left child of node
        Node* rightChild;       //right child of node

        Node(int value);        //constructor for node
        Node();                 //constructor for leaves
        ~Node();                //deconstructor
};

class AVLTree{
    private:
        Node* root;             //very root of AVL Tree
        int numNodes;           //number of Nodes in AVL Tree

        string space = "    ";  //used for printing
        int spaceCount = 1;

    public:
        AVLTree(int rootValue); //constructor
        ~AVLTree();             //deconstructor

        int size();             //number of elements in the AVL Tree
        bool empty();           //Is size == 0
        Node* find(int k);      //if the tree has a Node w/ key k, return it
                                //else, return a reference to a special Node END
        Node* put(int k);       //adds k to the AVLTree (duplicates are allowed) and returns its Node
        void erase(int k);      //erase an entry w/ the key k
        Node* getEnd();         //Returns the speical Node END

        void print(Node* n);    //Prints each node in the tree, indented, on a seperate line using
                                //a preorder traversal. Use a 3 or 4 space indent.
                                //To print the node of the tree, print the key at that node, followed
                                //by the height of the node in parentheses. If node is external print
                                //"L" for the key

        Node* getRoot();                        //returns root of AVL Tree
        int max(int x, int y);                  //max of 2 integers, used to determine height for node by comparing children
        int height(Node* n);                    //returns height of node, if node is a leaf, it returns 0
        int balance(Node* n);                   //determines the different between left and right child
        Node* leftRotation(Node* n);            //shifts the AVL tree at that node, acts as a root, to the left
        Node* rightRotation(Node* n);           //shifts the AVL tree at that node, acts as a root, to the right
        Node* putRecursive(Node* n, int k);     //same function for put, but uses a node for reference and uses recurrsive calls
        Node* eraseRecursive(Node* n, int k);   //same function for erase, but uses a node for reference and uses recurrsive calls
};

#endif