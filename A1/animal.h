#include <string>

// Animal Class, with private variable for age in months, and public methods
class Animal{

    private:
        int age_in_months;

    public:
        virtual std::string noise();
        int repeats();
        void print();
        int ageInMonths();
        Animal();
        Animal(int age);
};
