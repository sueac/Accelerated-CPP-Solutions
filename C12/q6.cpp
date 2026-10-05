#include <iostream>
#include "MyStr.h"

using std::cout;
using std::endl;

int main()
{
    MyStr s1;
    MyStr s2 = "Hello, world!";
    cout << "s1 is " << (s1 ? "not empty" : "empty") << endl;
    cout << "s2 is " << (s2 ? "not empty" : "empty") << endl;
    return 0;
}
