// Subclass Mouse, which is part of animal
// Has all its methods, with its own noise and repeats
class Mouse : public Animal {

public:
    Mouse();

    Mouse(int age);

    std::string noise();

    int repeats();

};

std::string Mouse::noise(){
    return "squeek";
}

int Mouse::repeats(){
    return 6;
}