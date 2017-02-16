#include <iostream>
#include <string>
using namespace std;

#include "food.h"

Food::Food() {
  name = "food";
  quantity = 0;
}

void Food::setName(string newName) {
  name = newName;
}

void Food::setQuantity(int newQuantity) {
  quantity = newQuantity;
}

string Food::getName() {
  return name;
}

int Food::getQuantity() const {
  return quantity;
}

void increaseQuantity(Food * food) {
    (*food).setQuantity((*food).getQuantity() + 1);
}

//assignment operator
Food & Food::operator>(Food & other)
{
  int amt1 = this->getQuantity();
  int amt2 = other.getQuantity();

  if (amt1 > amt2)
    return *this;
  else
    return other;

}
