#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

using std::domain_error;
using std::vector;
using std::sort;
using std::cout;
using std::endl;

typedef vector<double>::size_type vec_sz;

// compute the median of vector<double>
// note that calling this function copies the entire argument vector

template <class Iter>
double median(Iter begin, Iter end) 
{
	if (begin == end) {
		throw std::domain_error("median of an empty sequence");
	}

	std::vector<double> copy(begin, end);
	std::sort(copy.begin(), copy.end());

	std::size_t size = copy.size();
	std::size_t mid = size / 2;
	return size % 2 == 0 ? (copy[mid] + copy[mid -1])/2 : copy[mid];




}	
	
double average(vector<double> vec) 
{
	vec_sz length = vec.size();

	double sum = 0.0;

	for (vec_sz i = 0; i < length; ++i) {
		sum += vec[i];
	}

	return sum / length;
}


int main() {
	double a[] = {70, 80, 90, 60, 100};
	vector<double> v = {1,2,3,4};

	cout << median(v.begin(), v.end()) << endl;
	cout << median(std::begin(a), std::end(a)) << endl;





}




