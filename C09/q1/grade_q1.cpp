#include <stdexcept>
#include <vector>
#include <algorithm>
#include "grade_q1.h"


using std::sort;
using std::domain_error;	using std::vector;

typedef vector<double>::size_type vec_sz;

//compute a students total grade from midterm, final and homework
double grade(double midterm, double final, double homework) {
	return 0.2*midterm + 0.4*final + 0.4 * homework;
}

//compute a student's overall grade from midterm and final exam grades
//and vector of homework grades.
//this function does not copy its arguments, because the median does so for us.

double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("student has done no homework");
	}
	return grade(midterm, final, median(hw));
}


double median(vector<double> vec) 
{

	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("median of an empty vector not possible");
	}

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}	
	
	
