#include <iostream>
#include <string>

using namespace std;

class student
{
  private:
    string name;
    int grade;

  public:
    student();
    string getName();
    void setName(string s);
    int getGrade();
    void setGrade(int i);
    void increment();
};
