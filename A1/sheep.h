// Subclass Sheep, which is part of animal
// Has all its methods, with its own noise and repeats
class Sheep : public Animal {

public:
    Sheep();

    Sheep(int age);

    std::string noise();

    int repeats();

};

std::string Sheep::noise(){
    return "baa";
}

int Sheep::repeats(){
    return 3;
}