#include "animal.h"
using namespace std;

animal::animal()
{
    type = "cat";
    food = "fish";
}

animal::animal(string newType, string newFood)
{
    type = newType;
    food = newFood;
}


void animal::setFood(string newFood)
{
    food = newFood;
}

void animal::setType(string newType)
{
    type = newType;
}



string animal::getFood()
{
    return food;
}



string animal::getType()
{
    return type;
}

void animal::print(){

    cout << "I am a " << type << "." << endl;

}
