#include <iostream>
using namespace std;

#include "animal.h"
#include "pet.h"

int main()
{
  pet * mypet = new pet();
  mypet->setName("Garfield");

  mypet->animal::print();
  mypet->print();

  delete mypet;
}
