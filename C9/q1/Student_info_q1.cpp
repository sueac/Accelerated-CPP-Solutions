#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade_q1.h"
#include "Student_info_q1.h"

using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::sort;

Student_info::Student_info(): midterm(0), final(0), stored_grade(0) { }
Student_info::Student_info(istream &is) { read(is); }

bool compare(const Student_info& x, const Student_info& y) {
	return x.name() < y.name();
}


istream& Student_info::read(istream &in) {
	in >> n >> midterm >> final;
	read_hw(in, homework);
	stored_grade = Student_info::grade();
	return in;
}

double Student_info::grade() const {
	return ::grade(midterm, final, homework);

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
