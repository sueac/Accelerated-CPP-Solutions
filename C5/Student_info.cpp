#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::sort;

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
	double midterm, final;
	vector<double> homework;
	//read and store student name, midterm and final 
	is >> s.name >> midterm >> final;

	//handle eof
	if (is) {
		read_hw(is, homework);
		//save only final grade
		s.final_grade = grade(midterm, final, homework);
	}

	return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//get rid of previous contents of array
		hw.clear();

		//read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		//clear input strea so that input will work for next student
		in.clear();
	}
	return in;




}
