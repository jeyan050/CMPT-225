#include <iostream>
#include <string>
#include <sstream>

#include "stack.h"
#include "arrayUtils.h"
#include "employee.h"
// #include "stack.cpp"
// #include "arrayUtils.cpp"
// #include "employee.cpp"

using namespace std;

void testStackUnderflow(){
    std::cout << "___________TestStackUnderFlow___________" << endl;
    Stack<int> Test1(4);
    try{                        // Try block, where push x1 and pop x2
        Test1.push(4);
        cout << endl;
        Test1.pop();
        Test1.pop();

                                // Test if after 2nd pop, will it go to catch
        cout << "Did not catch exception" << endl;
    }
    catch(EmptyStackException x){
        cout << endl;
        cout << "Caught EmptyStackException" << endl;
    }
    cout << endl;
    return;
}

void testStackGrowth(){
    cout << "___________TestStackGrowth___________" << endl;
    Stack<int> Test2(4) ;
    for(int i = 0; i <= 4; i++){        // Push numbers into int Stack up to 4
        Test2.push(i+1);
    }
    cout << endl;
                                        // Display Capacity after 5 numbers
    cout << "Current Capacity is: "<< Test2.capacity() << endl << endl;

    for(int a = 5; a < 9; a++){         // Push numbers into int Stack up to 9
        Test2.push(a+1);
    }
    cout << endl;
                                        // Display Capacity after 10 numbers
    cout << "Current Capacity is: " << Test2.capacity() << endl << endl;

    for (int a = 0; a < 9; a++){        // Pop out all the numbers while also displaying them
        Test2.pop();
    }
    cout << endl;
    return;
}

void testReverseIntegers(){
    cout << "___________TestReverseIntegers___________" << endl;
    int Test3[12];
    for(int x = 0; x < 12; x++){        // Place 12 numbers in array
        Test3[x] = x+1;
    }
    cout << endl;
    cout << "[";                   // Display those 12 numbers
    for (int a = 0; a < 12; a++){
        if (a != 11){cout << Test3[a] << " , ";}
        else{cout << Test3[a];}
    }
    cout << "]" << endl << endl;

    ArrayUtils<int> reverseTest3;       // Reverse the array
    reverseTest3.reverse(Test3, 12);
    
    cout << endl;

    cout << "[";                   // Display reverse array of numbers
    for (int a = 0; a < 12; a++){
        if (a != 11){cout << Test3[a] << " , ";}
        else{cout << Test3[a];}
    }
    cout << "]" << endl; 
    cout << endl;

    return;
}

void testReverseStrings(){
    cout << "___________TestReverseStrings___________" << endl << endl;
    string Test4[12];                //Array of Strings w/ various words
    Test4[0] = "Abe";
    Test4[1] = "Bee";
    Test4[2] = "Cup";
    Test4[3] = "Dog";
    Test4[4] = "Elf";
    Test4[5] = "Fun";
    Test4[6] = "Gal";
    Test4[7] = "Hey";
    Test4[8] = "Ink";
    Test4[9] = "Jab";
    Test4[10] = "Key";
    Test4[11] = "Lip";

    cout << "[";                 // Display each word in array
    for (int a = 0; a < 12; a++){
        if (a != 11){cout << Test4[a] << " , ";}
        else{cout << Test4[a];};
    }
    cout << "]" << endl << endl;

    ArrayUtils<string> reverseTest4;  // Reverse the array of words
    reverseTest4.reverse(Test4, 12);

    cout << endl;

    cout << "[";                 // Display reversed array of words
    for (int a = 0; a < 12; a++){
        if (a != 11){cout << Test4[a] << " , ";}
        else{cout << Test4[a];};
    }
    cout << "]" << endl << endl;

    return;
}

void testReverseEmployees(){
    cout << "___________TestReverseEmployees___________" << endl << endl;
    Employee *Test5[12];                        // Creates an array of Employees
    Test5[0] = new Employee(201 ,"Abe");        // each with their own ID number and name
    Test5[1] = new Employee(202 ,"Bob");
    Test5[2] = new Employee(203 ,"Charlie");
    Test5[3] = new Employee(204 ,"Danny");
    Test5[4] = new Employee(205 ,"Ezio");
    Test5[5] = new Employee(206 ,"Fred");
    Test5[6] = new Employee(207 ,"Gary");
    Test5[7] = new Employee(208 ,"Hugh");
    Test5[8] = new Employee(209 ,"Ian");
    Test5[9] = new Employee(210 ,"Jake");
    Test5[10] = new Employee(211 ,"Kenny");
    Test5[11] = new Employee(212 ,"Larry");


    for (int a = 0; a < 12; a++){           //Display each employee's ID number and name
        cout << Test5[a]->toString() << endl;
    }
    cout << endl;

    ArrayUtils<Employee*> reverseTest5;      // Reverses Array of employees
    reverseTest5.reverse(Test5, 12);

    cout << endl << "Reverse:" << endl;

    for (int i = 0; i < 12; i++){           // Display the revered array of employees
        cout << Test5[i]->toString() << endl;       
    }

    return;
}

int main(){                 // Main to call those test functions
    testStackUnderflow();
    testStackGrowth();
    testReverseIntegers();
    testReverseStrings();
    testReverseEmployees();
    return 0;
}