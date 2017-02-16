#include <iostream>
#include <cstdint>
#include "food.h"
#include <string>

using namespace std;

void increaseQuantity(food * obj)
{

  obj->increment();

}


int main()
{

  food * pizza = new food();
  pizza->setQuantity(5);
  pizza->setName("pizza");
  cout << "You have " << pizza->getQuantity() << " pizzas." << endl;

  increaseQuantity(pizza);

  cout << "You have " << pizza->getQuantity() << " pizzas." << endl;

}
