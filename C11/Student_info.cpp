#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::domain_error;
using std::sort;

Student_info::Student_info(): midterm(0), final(0) {
	cout << "create" << endl;

}
Student_info::Student_info(istream &is): midterm(0), final(0) { 
	cout << "create" << endl;	
	read(is);
}

Student_info::Student_info(const Student_info& s) {
	cout << "copy" << endl;
	this->n = s.n;
	this->midterm = s.midterm;
	this->final = s.final;
	this->homework = s.homework;
}

Student_info& Student_info::operator=(const Student_info& rhs) {
	cout << "assign" << endl;
	this->n = rhs.n;
	this->midterm = rhs.midterm;
	this->final = rhs.final;
	this->homework = rhs.homework;
	return *this;

}

Student_info::~Student_info() {
	cout << "destroy" << endl;

}

bool compare(const Student_info& x, const Student_info& y) {
	return x.name() < y.name();
}


istream& Student_info::read(istream& in) {
	in >> n >> midterm >> final;
	read_hw(in, homework);
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
