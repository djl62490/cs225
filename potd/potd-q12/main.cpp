#include <iostream>
#include <string>
#include "square.h"
using namespace std;

int main(){
    Square a;
    Square b = a;
    Square c(a);
    Square d = a + b;
    cout << a.getLength() << endl;
    cout << b.getLength() << endl;
    cout << d.getLength() << endl;
    cout << a.getName() << endl;
    cout << b.getName() << endl;
    cout << d.getName() << endl;
    return 0;

}
