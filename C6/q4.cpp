#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <iostream>

using std::vector;
using std::copy;
using std::back_inserter;
using std::cout;
using std::endl;

int main() {
	vector<int> u(10,1000000000);
	vector<int> v;
	
	double start = clock();
	copy(u.begin(), u.end(), back_inserter(v));
	double end = clock();

	cout << (end - start) / CLOCKS_PER_SEC << " seconds" << endl;

	v.clear();

	start = clock();
	v = u;
	end = clock();

	cout << (end - start) / CLOCKS_PER_SEC << " seconds" << endl;

}

