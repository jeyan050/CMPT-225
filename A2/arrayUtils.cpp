#include "arrayUtils.h"

template <typename T>
T* ArrayUtils<T>::reverse(T *usedArray, int size){      //reverse Function
    Stack<T> A(size);
    int a = 0;
    for( int a = 0; a < size ; a++){       //Puts elements in array into Stack
        A.push(usedArray[a]);
    }
    cout << endl;
    for (int x = 0; x < size; x++){        //Puts back elements into array, but in reverse order
        usedArray[x] = A.pop();
    }
    return usedArray;
}