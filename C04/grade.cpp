#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"


using std::domain_error;	using std::vector;

//compute a students total grade from midterm, final and homework
double grade(double midterm, double final, double homework) {
	return 0.2*midterm + 0.4*final + 0.4 * homework;
}

//compute a student's overall grade from midterm and final exam grades
//and vector of homework grades.
//this function does not copy its arguments, because the median does so for us.

double grade(double midterm, double final, vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("student has done no homework");
	}
	return grade(midterm, final, median(hw));
}
	
