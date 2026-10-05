#include <iostream>
#include "MyStr.h"

using std::cout;
using std::endl;

int main()
{
    MyStr s1 = "a";
    MyStr s2 = "b";
    MyStr s3 = "c";
    cout << "s1 is " << (s1 > s2 ? "larger" : "smaller") << " than s2" << endl;
    cout << "s3 is " << (s3 < s1 ? "smaller" : "larger") << " than s1" << endl;
    return 0;
}
