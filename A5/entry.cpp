#include <string>
#include <iostream>
#include <time.h>

using namespace std;

#include "entry.h"

Entry::Entry(){                     //constructor
    random();
}

Entry::Entry(int num){
    key = num;

    string randomString = "";
    char char1;
    for (int i = 0; i < 3; i++){
        char1 = rand() % 26 + 'a';
        data += char1;
    }
}

Entry::Entry(int num, string str){
    key = num;
    data = str;
}

void Entry::random(){               //deconstructor
    key = rand()%99+0;

    string randomString = "";
    char char1;
    for (int i = 0; i < 3; i++){
        char1 = rand() % 26 + 'a';
        data += char1;
    }
}

int Entry::getKey(){                //returns key
    return key;
}

string Entry::getData(){            //returns data
    return data;
}

string Entry::toString(){           //converts entry to a string
    string stringKey = to_string(key);
    string outputString = "(" + stringKey + ", " + data + ")";
    return outputString; 
}