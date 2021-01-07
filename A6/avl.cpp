#include <string>
#include <iostream>

#include "avl.h"

using namespace std;

Node::Node(int value){          //constructor for Node, sets values and pointers for Node
    this->key = value;
    this->height = 1;

    this->leftChild = NULL;
    this->rightChild = NULL;
}

Node::Node(){          //constructor for Node, sets values and pointers for Node
    this->key = 0;
    this->height = 0;
    this->leftChild = NULL;
    this->rightChild = NULL;
}

Node::~Node(){                  //deconstructor for Node
    if(leftChild)
        delete leftChild;
    if(rightChild)
        delete rightChild;
    delete this;
}

//------------------------------------------------//

AVLTree::AVLTree(int rootValue){                //constructor for AVL Tree, sets root Node and updates numNodes
    this->root = new Node(rootValue);
    root->leftChild = new Node();
    root->rightChild = new Node();

    this->numNodes = 1;
}

AVLTree::~AVLTree(){                            //delete AVL tree by deleting root Node
    delete root;
}

int AVLTree::size(){                            //returns size of Nodes
    return numNodes;
}

bool AVLTree::empty(){                          //returns if AVL Tree is empty
    return (numNodes==0);
}

Node* AVLTree::getRoot(){                       //returns root of AVL Tree
    return root;
}

int AVLTree::max(int x, int y){                 //returns max of 2 integers
    return (x > y)? x : y;
}

int AVLTree::height(Node* n){                   //returns height of node
    return n->height;
}

int AVLTree::balance(Node* n){                  //determines the balacne of the tree (difference between childfren nodes)             
    return height(n->leftChild) - height(n->rightChild);
}

Node* AVLTree::rightRotation(Node* n){          //rotates pivot to the right
    Node* oldLeftN = n->leftChild; 
    Node* rightNChild = oldLeftN->rightChild;

    oldLeftN->rightChild = n;       //set n to be right child of oldLeftN
    n->leftChild = rightNChild;     //set n's new leftChild to be oldLeftN's rightChild

    n->height = max(height(n->leftChild), height(n->rightChild)) +1;        //updates height
    oldLeftN->height = max(height(oldLeftN->leftChild), height(oldLeftN->rightChild)) +1;

    if (n == root){         //if we rotated the root, we update it to show the new root
        root = oldLeftN;
    }
    return oldLeftN;
}

Node* AVLTree::leftRotation(Node* n){           //rotates privot to the left
    Node* oldRightN = n->rightChild;         
    Node* leftNChild = oldRightN->leftChild;

    oldRightN->leftChild = n;       //set n to be left child of oldRightN
    n->rightChild = leftNChild;     //set n's new rightChild to be oldRightN's leftChild

    n->height = max(height(n->leftChild), height(n->rightChild)) +1;       //updates heights
    oldRightN->height = max(height(oldRightN->leftChild), height(oldRightN->rightChild)) +1;

    if (n == root){         //if we rotated the root, we update it to show the new root
        root = oldRightN;
    }
    return oldRightN;
}

Node* AVLTree::getEnd(){                        //special node for END
    Node* end = new Node(-2147483648);
    return end;
}

Node* AVLTree::find(int k){                     //find node in AVL Tree
    Node* current = root;
    while(current->key != 0){     //goes down AVL Tree until it finds a node with same Key
        if (k < current->key){
            current = current->leftChild;
        } else if (k > current->key){
            current = current->rightChild;
        } else {
            return current;
        }
    }
    return getEnd();    //if it doesn't find it and ends up on a leaf, it returns END node
}

Node* AVLTree::putRecursive(Node* n, int k){    //put function that uses root, and uses recursive calls as it goes down tree
    if(n->key == 0){  //if reaches a leaf, it changes the leaf to be that Node with key k
        n->key = k;
        n->height++;
        n->leftChild = new Node();
        n->rightChild = new Node();
        return n;
    }

    if (k <= n->key){   //goes down AVL Tree, and updates the whole tree after it inserts (including the height)
        n->leftChild = putRecursive(n->leftChild, k);
    } else { //if (k >= n->key)
        n->rightChild = putRecursive(n->rightChild, k);
    }

    n->height = max(height(n->leftChild), height(n->rightChild)) +1; //change height

    int checkBalance = balance(n);  //determines number to see if its unbalanced (if > 1 or < -1 then its unbalanced)

    //4 difference cases 
    if (checkBalance > 1 && k < n->leftChild->key)              //single rotation: left
        return rightRotation(n);
    if (checkBalance < -1 && k > n->rightChild->key)            //single rotation: right
        return leftRotation(n);
    if (checkBalance > 1 && k > n->leftChild->key){             //double rotation: left - right
        n->leftChild = leftRotation(n->leftChild);
        return rightRotation(n);
    }
    if (checkBalance > 1 && k > n->rightChild->key){            //double rotation: right - left
        n->rightChild = rightRotation(n->rightChild);
        return leftRotation(n);
    }
    return n;
}

Node* AVLTree::put(int k){                      //put function but uses the other put function that uses root Node
    return putRecursive(root, k);
    numNodes++;
}

Node* AVLTree::eraseRecursive(Node* n, int k){  //erase function that uses root, and uses recursive calls as it goes down tree
    if (n->key == 0)    //if empty AVL Tree, then you can't delete any nodes
        return n;

    if (k < n->key){    //goes down AVL Tree until it finds a node with same key
        n->leftChild = eraseRecursive(n->leftChild, k); 
    } else if (k > n->key){ 
        n->rightChild = eraseRecursive(n->rightChild, k);
    } else {    //if theres a node with same key
        if (n->leftChild->key == 0 || n->rightChild->key == 0){     //if 1 or no child
            Node* temp = n->leftChild; 
            if (temp->key == 0)
                temp = n->rightChild;
            
            if (temp->key == 0){  //no child case
                temp = n;
                n = new Node();
            } else {    //1 child
                *n = *temp;     //copy contents of child
            }
            free(temp);         
        } else {                                                    //if has 2 children
            Node* temp = n->leftChild;
            while (temp->leftChild->key != 0)     //finds successor for node n
                temp = temp->leftChild;

            n->key = temp->key; //sets node's key to be that sucessor's key
            n->leftChild = eraseRecursive(n->leftChild, temp->key);     //goes down and delete node
        }
    }
    if (n->key == 0){    //If has only 1 node, so after deletion it could be empty
        return n;
    }

    n->height = max(height(n->leftChild), height(n->rightChild)) +1;    //determiens height of node by using children's height

    int checkBalance = balance(n);

    if (checkBalance > 1 && balance(n->leftChild) >= 0){    //single rotation: left
        return rightRotation(n);
    }
    if (checkBalance < -1 && balance(n->rightChild) <= 0){  //single rotation: right
        return leftRotation(n);
    }
    if (checkBalance > 1 && balance(n->leftChild) < 0){     //double rotation: left - right
        n->leftChild = leftRotation(n->leftChild);
        return rightRotation(n);
    }
    if (checkBalance < -1 && balance(n->rightChild) > 0){   //double rotation: right - left
        n->rightChild = rightRotation(n->rightChild);
        return leftRotation(n);
    }
    return n;
}

void AVLTree::erase(int k){                     //put function but uses the other put function that uses root Node
    eraseRecursive(root, k);
    numNodes--;
}

void AVLTree::print(Node* n){                   //print function to print AVL Tree
    if (n->key != 0){
        cout << n->key << " (" << n->height << ")" << endl;     //prints key and height (in brackets)
        spaceCount++;
        int tempSpace = spaceCount;

        if (n->leftChild->key != 0){      //prints left Child and spaces it 
            for (int i = 1; i < spaceCount; i++){
                cout << space;
            }
            print(n->leftChild); 
        } else {    //if ends up to leaf node, it prints L and leaf's height
            for (int i = 1; i < spaceCount; i++){
                cout << space;
            }
            cout << "L" << " (" << n->leftChild->height << ")" << endl;
        }
        
        if (n->rightChild->key != 0){     //prints right Child and spaces it 
            spaceCount = tempSpace;
            for (int i = 1; i < spaceCount; i++){
                cout << space;
            }
            print(n->rightChild);
        } else {    //if ends up to leaf node, it prints L and leaf's height
            spaceCount = tempSpace;
            for (int i = 1; i < spaceCount; i++){
                cout << space;
            }
            cout << "L" << " (" << n->rightChild->height << ")" << endl;
        }
    } 
    if (n == root){     //resets the amount of spaces for next time print is called
        spaceCount = 1;
    }
    return;
}