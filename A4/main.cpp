#include <string>
#include <iostream>

#include "heap.cpp"

using namespace std;

void print(Entry output[], int length){ //print functions to print array of entries
    for(int i = 0; i < length; i++){
        cout << output[i].toString()<< " ";
    }
    cout << "\n";
}

void heapSort1(Entry entries[], int n){ //sort using insert()
    Heap tempHeap(n);
    for(int i = 0; i < n; i++){
        tempHeap.insert(entries[i]);
    }
    entries = tempHeap.heapSort();
    print(entries, n);
}

void heapSort2(Entry entries[], int n){ //sort using make()
    Heap tempHeap(n);
    tempHeap.make(entries, n);
    entries = tempHeap.heapSort();
    print(entries, n);
}

int main(){
    cout << "___________HeapSort#1 with 15 entries___________" << endl;
    Entry Test1[15];
    print(Test1,15);
    heapSort1(Test1,15);
    cout << endl;

    cout << "___________HeapSort#2 with 15 entries___________" << endl;
    Entry Test2[10];
    print(Test2,10);
    heapSort1(Test2,10);
    cout << endl;

    cout << "___________HeapSort#1 with 31 entries___________" << endl;
    Entry Test3[31];
    print(Test3,31);
    heapSort1(Test3,31);
    cout << endl;

    cout << "___________HeapSort#2 with 31 entries___________" << endl;
    Entry Test4[31];
    print(Test4,31);
    heapSort1(Test4,31);
    cout << endl;

    return 0;
}