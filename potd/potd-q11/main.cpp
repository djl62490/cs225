#include <iostream>
using namespace std;

#include "square.h"

int main() {
  square * s1 = new square();
  square s2;
  s1->name = "little square";
  //cout << "check 1" << endl;
  *s1->length = 1.5;
  s2.name = "big square";
  *s2.length = 5.0;

  //cout << "check 2" << endl;

  square *s3 = new square(*s1);
  //cout << "check 3" << endl;
  square s4(s2);

  delete s1;


  cout << *s3->length << endl;
  cout << *s4.length << endl;
  //cout << *s1->length << endl;


}
