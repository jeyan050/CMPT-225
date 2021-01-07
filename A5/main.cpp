#include <string>
#include <iostream>
#include <bits/stdtr1c++.h>
#include <time.h>

using namespace std;

#include "skiplist.cpp"

int main(){
    cout << "______________________Test#1______________________" << endl;

    SkipList test1;                 //test 1 with 8 entries

    int deleteNumber;
    int findNumber;

    for(int i = 0; i < 8; i++){
        int k = 0;
        string v = "";

        k = rand()%99+0;

        char char1;
        for (int i = 0; i < 1; i++){
            char1 = rand() % 26 + 'a';
            v += char1;
        }
        test1.put(k,v);
        cout << endl;

        if(i == 2){
            findNumber = i;
        }

        k = deleteNumber;
    }

    test1.print();

    
    test1.erase(deleteNumber);
    test1.print();

    test1.find(findNumber);
    test1.find(deleteNumber);

    test1.greaterEntry(25);
    test1.lessEntry(25);

    cout << "______________________Test#2______________________" << endl;

    SkipList test2;                     //test 2 with inserting 40 entries and printing the skiplist

    for(int i = 0; i < 3; i++){
        int k = 0;
        string v = "";

        k = rand()%99+0;

        char char1;
        for (int i = 0; i < 3; i++){
            char1 = rand() % 26 + 'a';
            v += char1;
        }
        cout << "created key and string values: " << k << " , "<< v << endl;
        test2.put(k, v);
        cout << endl;
    }

    test2.print();
    
}