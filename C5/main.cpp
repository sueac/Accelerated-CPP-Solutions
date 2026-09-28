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

typedef vector<Student_info> Student_container;
//typedef list<Student_info> Student_container;
typedef vector<Student_info>::size_type vec_std_sz;


bool fgrade(const Student_info& s) {
	return s.final_grade < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vec_std_sz i = 0;

    // invariant: elements [0, i) of students represent passing grades
    while (i != students.size()) {
        if (students[i].final_grade < 60) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        } else
            ++i;
    }
    return fail;
}


vector<Student_info> resize_extract_fails(vector<Student_info>& students) {
	Student_container fail;
	Student_container::size_type pass = 0;

	for(Student_container::size_type i = 0; i != students.size(); ++i) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
		} else {
			students[pass] = students[i];
			pass++;
		}
	}

	students.resize(pass);
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
	Student_container::size_type total_students = students.size();
	
	
	double begin = std::clock();
	Student_container failed_students = resize_extract_fails(students);
	double end = std::clock();

	cout << "Extracting fails for " << total_students << " students took " << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

	

	
/*	
	for (Student_container::size_type i = 0; i != students.size(); i++) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		streamsize prec = cout.precision();		
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);

		cout << endl;
	}
*/
	

	return 0;	

}
