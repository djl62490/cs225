#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

class animal{

    private:

    string type;
    string food;

    public:

    animal();
    animal(string newType, string newFood);
    void setType(string newType);
    void setFood(string newFood);
    string getType();
    string getFood();
    virtual void print();
};

#endif
