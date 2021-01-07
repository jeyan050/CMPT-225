#include <iostream>
#include <string>
#include <sstream>

#include "arraylist.h"

using namespace std;

void testArrayListUnderflow(){
    cout << "___________TestArrayUnderFlow___________" << endl; // testArrayListUnderflow
    try {
        MyArrayList<int> Test1;
        int e = 1;
        Test1.insertFront(e);
        Test1.removeFront();
        Test1.removeFront();

        cout << "Did not catch exception" << endl;
    }
    catch (EmptyListException x){
        cout << endl;
        cout << "Caught EmptyListException" << endl;
    }
    cout << endl;

    try {
        MyArrayList<int> Test2;
        int e = 1;
        Test2.insertFront(e);
        Test2.removeBack();
        Test2.removeBack();

        cout << "Did not catch exception" << endl;
    }
    catch (EmptyListException x){
        cout << endl;
        cout << "Caught EmptyListException" << endl;
    }
    cout << endl;

    try{
        MyArrayList<int> Test3;
        int e = 1;
        Test3.insertFront(e);
        MyArrayList<int>::Iterator p = Test3.begin();
        Test3.remove(p);
        Test3.remove(p);

        cout << "Did not catch exception" << endl;
    }
    catch (EmptyListException x){
        cout << endl;
        cout << "Caught EmptyListException" << endl;
    }
    cout << endl;

    return;
}

void testIntegerIterator(){ // testIntegerIterator
    cout << "___________TestIntegerIterator___________" << endl;
    MyArrayList<int> TestInt(4);

    int e = 1;
    for (int i = 0; i < 6; i++){
        TestInt.insertBack(e);
        e+= 1;
    }

    MyArrayList<int>::Iterator check = TestInt.end();

    MyArrayList<int>::Iterator iter = TestInt.begin();
    while(iter.operator==(check) != true){
        cout << iter.operator*() << " ";
        iter.operator++();
    }
    cout << iter.operator*() << " ";

    cout << endl;

    TestInt.removeFront();
    TestInt.removeFront();
    TestInt.removeFront();

    int f = 9;
    TestInt.insertBack(f);
    TestInt.insertBack(f);
    TestInt.insertBack(f);

    MyArrayList<int>::Iterator check2 = TestInt.end();
    
    MyArrayList<int>::Iterator iter2 = TestInt.begin();
    while(iter2.operator==(check2) != true){
        cout << iter2.operator*() << " ";
        iter2.operator++();
    }
    cout << iter2.operator*() << " ";

    cout << endl;
    cout << endl;

    return;
}

void testStringIterator(){ // testStringIterator
    cout << "___________TestStringIterator___________" << endl;
    MyArrayList<string> TestStr(4);

    string a = "A";
    TestStr.insertBack(a);
    string b = "B";
    TestStr.insertBack(b);
    string c = "C";
    TestStr.insertBack(c);
    string d = "D";
    TestStr.insertBack(d);
    string e = "E";
    TestStr.insertBack(e);
    string f = "F";
    TestStr.insertBack(f);

    MyArrayList<string>::Iterator check = TestStr.end();

    MyArrayList<string>::Iterator iter = TestStr.begin();
    while(iter.operator==(check) != true){
        cout << iter.operator*() << " ";
        iter.operator++();
    }
    cout << iter.operator*() << " ";

    cout << endl;

    TestStr.removeFront();
    TestStr.removeFront();
    TestStr.removeFront();

    string cmpt = "cmpt";
    TestStr.insertBack(cmpt);
    string isThe = "isThe";
    TestStr.insertBack(isThe);
    string best = "best";
    TestStr.insertBack(best);

    MyArrayList<string>::Iterator check2 = TestStr.end();
    
    MyArrayList<string>::Iterator iter2 = TestStr.begin();
    while(iter2.operator==(check2) != true){
        cout << iter2.operator*() << " ";
        iter2.operator++();
    }
    cout << iter2.operator*() << " ";

    cout << endl;

    return;
}

int main(){                 // Main to call those test functions
    testArrayListUnderflow();
    testIntegerIterator();
    testStringIterator();
    return 0;
}
