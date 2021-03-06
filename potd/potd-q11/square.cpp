#include "square.h"
#include <string>
#include <iostream>

using namespace std;

square::square()
{
  name = "mysquare";
  length = new double(2.0);
}

square::square(const square & orig)
{
  cout << "I am copying!" << endl;
  name = orig.name;
  length = new double(2.0);
  *length = *orig.length;
  cout << "I am copying!" << endl;
}

square::~square()
{
  delete length;
}
