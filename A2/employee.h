#include <string>
#include <iostream>

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

using namespace std;

class Employee{
    private:
        int idNum;                      //ID number
        string name;                    //Name of Employee
    public:
        Employee(int id, string nam);   //Constructor for Employee
        int getID();                    //Getter for ID number
        string getName();               //Getter for name
        string toString();              //Combine name and ID number into a string
};

#endif