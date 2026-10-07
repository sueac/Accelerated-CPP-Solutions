#include <algorithm>
#include <iostream>

using std::min;

#include "Core.h"
#include "grade.h"

using std::istream;
using std::string;
using std::vector;
using std::cout;
using std::endl;



std::istream& read_hw(std::istream& in, std::vector<double>& hw);

string Core::name() const { 
	//Q2
	//cout << "core name" << endl;
	return n; 
}

double Core::grade() const {
	//Q2
	//cout << "core grade" << endl;
	return ::grade(midterm, final, homework);
}

//Q4
string Core::letter_grade() const {

	double grade = this->grade();

	//range posts for numeric grades
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	//namesfor the letter grades
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	//compute the number of grades given the size of the array
	//and the size of a single element
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	//given a numeric grade, find and return the associated letter grade
	for (size_t i = 0; i < ngrades; i++) {
		if (grade >= numbers[i])
			return letters[i];
	}

	return "?\?\?";
}

//Q6
double PassFail::grade() const {
	if (homework.empty()) {
		return (final + midterm) / 2.0;
	} else {
		return Core::grade();
	}


}

istream& Core::read_common(istream& in) {
	in >> n >> midterm >> final;
	return in;
}

istream& Core::read(istream& in) {
	read_common(in);
	read_hw(in, homework);
	return in;
}

istream& Grad::read(istream& in) {
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const {
	//Q2
	//cout << "grad grade" << endl;
	return min(Core::grade(), thesis);
}

bool compare(const Core& c1, const Core& c2) {
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
	return compare(*cp1, *cp2);
}

bool compare_ptr(const Ptr<Core>& p1, const Ptr<Core>& p2) {
	return compare(*p1, *p2);
}

