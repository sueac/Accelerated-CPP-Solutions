#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main() {
	cout << "Enter an array of numbers, "
		"followed by e-o-f: ";
	vector<double> array;
	double input;

	while (cin >> input) {
		array.push_back(input);
	}	

	typedef vector<double>::size_type vec_sz;
	vec_sz size = array.size();

	if (size <= 3) {
		
		cout << endl << "Need atleast 4 elements for quartiles!" << endl;

		return 1;
	}

	sort(array.begin(), array.end());

	for (int i = 0; i < size; i++) {
		if (i == 0) 
			cout << "First quartile: ";
		else if (i 



	}

	return 0;



}
