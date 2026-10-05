#include <iostream>
#include "MyStr.h"

using std::cout;
using std::endl;

int main()
{
    MyStr s = "Hello, world!";

    // print one char at a time
    for (MyStr::const_iterator it = s.begin();
         it != s.end(); ++it)
         cout << *it << endl;
    return 0;
}
