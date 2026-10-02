#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::sort;
using std::cout;
using std::endl;


//generic median method
template<class T, class In>
T median(In b, In e) {

	size_t size = e-b;	
	
	if (b == e) {
		throw std::domain_error("median of an empty vector");
	}

	sort(b, e);

	size_t mid = size/2;

	return size % 2 == 0 ? (*(b + mid) + *(b + mid - 1)) / 2.0 : *(b+mid);

}


int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(4);

	cout << "Median: " << median<double>(vec.begin(), vec.end()) << endl;

}
