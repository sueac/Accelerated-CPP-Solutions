#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

using std::string;
using std::vector;
using std::endl;
using std::cout;

int main() {
	vector<string> v;
	v.push_back("Hello");
	v.push_back("World");

	cout << std::accumulate(v.begin(), v.end(), string()) << endl;



}
