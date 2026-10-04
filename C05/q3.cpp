#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include "grade.h"
#include "Student_info.h"

using std::cout; using std::setprecision;
using std::cin;  using std::sort;
using std::domain_error;
using std::streamsize;
using std::endl; using std::string;
using std::max;  using std::vector;
using std::list;

//typedef vector<Student_info> Student_container;
typedef list<Student_info> Student_container;


bool fgrade(const Student_info& s) {
	return s.final_grade < 60;
}

Student_container extract_fails(Student_container& students) {
	Student_container fail;
	Student_container::iterator iter = students.begin();

	while (iter != students.end()) {
		if(fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}

	}
	

	return fail;
}

//make seperate sort functions for vector and list

void Sort(vector<Student_info>& students) {
	sort(students.begin(), students.end(), compare);
}

void Sort(list<Student_info>& students) {
	students.sort(compare);
}


int main() {

	Student_container students;
	Student_info record;
	string::size_type maxlen = 0;

	cout << "Enter student data: " << endl;

	while(read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	Sort(students);

/*	
	for (Student_container::size_type i = 0; i != students.size(); i++) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		streamsize prec = cout.precision();		
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);

		cout << endl;
	}
*/
	Student_container::size_type total_students = students.size();
	
	
	double begin = std::clock();
	Student_container failed_students = extract_fails(students);
	double end = std::clock();

	cout << "Extracting fails for " << total_students << " students took " << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;	

	return 0;	

}
