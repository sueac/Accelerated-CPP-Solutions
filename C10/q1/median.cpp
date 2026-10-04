#include <stdexcept>
#include <vector>
#include <algorithm>
#include "median.h"

using std::domain_error;
using std::vector;
using std::sort;

typedef vector<double>::size_type vec_sz;

// compute the median of vector<double>
// note that calling this function copies the entire argument vector

double median(vector<double< vec) 
{

	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("median of an empty vector not possible");
	}

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
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






