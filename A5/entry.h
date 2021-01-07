#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Entry{
    private:
        int key;
        string data;


    public:
        Entry();            //constructors
        Entry(int num);
        Entry(int num, string str);
        void random();      //gives a random key btwn 0 - 99 inclusive, and a
                            //random data string of 3 lowercase letters
        int getKey();       //get Key value
        string getData();   //get Data value
        string toString();  //converts entry to a string, ex: (14,drn)
};

#endif