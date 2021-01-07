// Subclass Cow, which is part of animal
// Has all its methods, with its own noise and repeats
class Cow : public Animal {

public: 
    Cow();

    Cow(int age);

    std::string noise();

    int repeats();

};

std::string Cow::noise(){
    return "moo";
}

int Cow::repeats(){
    return 1;
}