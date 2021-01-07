// Subclass Crow, which is part of animal
// Has all its methods, with its own noise and repeats
class Crow : public Animal {

public:
    Crow();

    Crow(int age);

    std::string noise();

    int repeats();

};

std::string Crow::noise(){
    return "caw";
}

int Crow::repeats(){
    return 6;
}