#include <iostream>
#include "MyStr.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    MyStr s;
    getline(cin, s);
    cout << s << endl;
    return 0;
}
