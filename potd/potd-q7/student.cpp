#include "student.h"
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

student::student()
{
  grade = 1;
  name = "unnamed";
}

string student::getName()
{
  return name;
}

void student::setName(string s)
{
  name = s;
}

int student::getGrade()
{
  return grade;
}

void student::setGrade(int i)
{
  grade = i;
}

void student::increment()
{
  grade++;
}
