#include "student.h"
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

void graduate(student * s)
{
  s->increment();
}

int main()
{
  student * frank = new student();
  frank->setName("Frank");
  frank->setGrade(8);

  cout << frank->getName() << " is in grade " << frank->getGrade() << "." <<endl;
  graduate(frank);
  cout << frank->getName() << " is in grade " << frank->getGrade() << "." <<endl;
}
