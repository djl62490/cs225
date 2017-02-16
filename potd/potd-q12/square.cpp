#include <iostream>
#include <string>
using namespace std;

#include "square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

void Square::copy(const Square & source)
{
  name = source.name;
  *lengthptr = *source.lengthptr;
}

void Square::clear()
{
  delete lengthptr;
}

const Square & Square::operator=(const Square & source)
{
  if (&source == this)
  {
    return * this;
  }
  else
  {
    this->clear();
    this->copy(source);
    return * this;
  }
}

const Square & Square::operator+(const Square & source)
{
  Square * x = new Square();
  *x->lengthptr = *this->lengthptr + *source.lengthptr;
  x->name = this->name + source.name;
  return *x;
}
