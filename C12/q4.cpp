#include <iostream>
#include "MyStr.h"

using std::cout;
using std::endl;

int main()
{
    MyStr s1 = "Hello, world!";
    MyStr s2 = "Goodbye, world!";
    MyStr s3 = "Hello, world!";
    cout << "s1 and s2 are " << (s1 == s2 ? "equal" : "not equal") << endl;
    cout << "s1 and s3 are " << (s1 == s3 ? "equal" : "not equal") << endl;
    return 0;
}
