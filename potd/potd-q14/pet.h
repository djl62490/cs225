#ifndef PET_H
#define PET_H


#include <iostream>
using namespace std;

#include "animal.h"

class pet : public animal
{
private:
  string name;
  string owner_name;

public:
  /*default constructor intializes type to cat, food to fish, name to fluffy, and
  owner name to Cinda*/
  pet();
  //constructor
  pet(string t, string f, string n, string o);
  virtual ~pet() {}

  //getters and setters
  void setName(string s);
  string getName();
  void setOwner(string s);
  string getOwner();

  /*Write a function print that prints "My name is ."
   where the blank is the value of the name variable.*/
  void print();
}
;

#endif
