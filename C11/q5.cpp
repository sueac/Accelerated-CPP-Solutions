#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Student_info.h"


using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;

string letter_grade(double grade) {
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

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			cout << letter_grade(final_grade) << endl;
		} catch (std::domain_error e) {
			cout << e.what() << endl;
		}

	}

}
