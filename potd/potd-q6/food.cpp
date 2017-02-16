#include "food.h"
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

food::food()
{

  quantity = 3;

}

int food::getQuantity()
{

  return quantity;

}


void food::setQuantity(int x)
{

  quantity = x;

}


string food::getName()
{

  return name;

}

void food::setName(string s)
{

  name = s;

}

void food::increment()
{

  quantity++;

}
