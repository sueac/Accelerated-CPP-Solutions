#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade_pf.h"
#include "Student_info_pf.h"

using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::sort;

Student_info_pf::Student_info_pf(): midterm(0), final(0) { }
Student_info_pf::Student_info_pf(istream &is) { read(is); }

bool compare(const Student_info_pf& x, const Student_info_pf& y) {
	return x.name() < y.name();
}


istream& Student_info_pf::read(istream &in) {
	in >> n >> midterm >> final; 
	return in;
}

double Student_info_pf::grade() const {
	return ::grade(midterm, final);

}

