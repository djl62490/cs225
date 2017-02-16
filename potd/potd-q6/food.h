#include <string>
#include <iostream>
using namespace std;

class food
{
  private:
    string name;
    int quantity;

  public:
    food();
    int getQuantity();
    void setQuantity(int x);
    string getName();
    void setName(string s);
    void increment();
};
