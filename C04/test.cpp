#include "median.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<double>::size_type vec_sz;

int main() {
	
	cout << "Enter a list of numbers followed by EOF: " << endl;

	double x;
	vector<double> nums;

	while (cin >> x) {
		nums.push_back(x);
	}

	cout << "Average: " << average(nums) << endl;
	cout << "Median: " << median(nums) << endl;

	return 0;








}
