#include <iostream>
using namespace std;

#include "animal.h"
#include "pet.h"

//default constructor
pet::pet():animal()
{
  setName("Fluffy");
  setOwner("Cinda");
}

pet::pet(string t, string f, string n, string o)
  : animal(t, f)
{
    setName(n);
    setOwner(o);
}


//getters and setters
void pet::setName(string s)
{
  name = s;
}

string pet::getName()
{
  return name;
}

void pet::setOwner(string s)
{
  owner_name = s;
}

string pet::getOwner()
{
  return owner_name;
}

//print function
void pet::print()
{
  cout << "My name is " << name << "." << endl;
}
