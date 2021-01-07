#include <iostream>
#include <string>
#include <sstream>

#include "animal.h"
#include "crow.h"
#include "sheep.h"
#include "cow.h"
#include "mouse.h"

using namespace std;

// Animal Methods
// Constructor
Animal::Animal(int age){
    age_in_months = age;
}

Animal::Animal(){}

// Animal Default Noise 
std::string Animal::noise(){
    return "grunt";
}

// Animal Default Repeats
int Animal::repeats(){
    return 5;
}

// Animal Print Function
void Animal::print(){
    std::cout << ageInMonths();
    for (int i = 0; i < repeats(); i++){
        std::cout << " " + noise();
    }
    std::cout << std::endl;
}

// Animal Default Age in Months
int Animal::ageInMonths(){
    return age_in_months;
}


// Crow Constructors
Crow::Crow(int age): Animal(age){}

Crow::Crow(){}

// Sheep Constructors
Sheep::Sheep(int age): Animal(age){}

Sheep::Sheep(){}

// Cow Constructors
Cow::Cow(int age): Animal(age){}

Cow::Cow(){}

// Mouse Constructors
Mouse::Mouse(int age): Animal(age){}

Mouse::Mouse(){}


// Main Function
int main(){

    // Print #1
    // Assign a variable for each subclass
    Crow crow1 = Crow(5);
    Sheep sheep1 = Sheep(8);
    Cow cow1 = Cow(12);
    Mouse mouse1 = Mouse(11);
    Animal animal1 = Animal(15);

    // Print Variables
    crow1.print();
    sheep1.print();
    cow1.print();
    mouse1.print();
    animal1.print();

    std::cout << std::endl;

    // Print #2
    // Create array for Animals
    Animal *animalArray[10];

    // Assign a subclass to each part of array
    animalArray[0] = new Crow(6);
    animalArray[1] = new Sheep(8);
    animalArray[2] = new Cow(13);
    animalArray[3] = new Mouse(12);
    animalArray[4] = new Animal(16);
    animalArray[5] = new Cow(14);
    animalArray[6] = new Mouse(4);
    animalArray[7] = new Crow(16);
    animalArray[8] = new Animal(7);
    animalArray[9] = new Sheep(8);

    // Print Array
    for(int i = 0; i < 10; i++){
        animalArray[i]->print();
    }

    // Delete elements in array
    for(int a = 0; a < 10; a++){
        delete animalArray[a];
    }
}
