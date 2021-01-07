#include <string>
#include <iostream>

#include "employee.h"

using namespace std;

Employee::Employee(int id, string nam){     //Constructor
    idNum = id;
    name = nam;
}

int Employee::getID(){return idNum;}        //Getter for ID number

string Employee::getName(){return name;}    //Getter for name of employee

string Employee::toString(){                //Combine name and ID number into a string
    string idN = to_string(getID());
    string person = getName();
    string fullID = person + " " + idN;
    return fullID;
}