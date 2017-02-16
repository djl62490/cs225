#include <iostream>
#include <string>

using namespace std;

class square
{
public:
  square();
  square(const square & orig);
  ~square();
  double * length;
  string name;

};
