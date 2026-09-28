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


bool fgrade(const Student_info& s) {
	return s.final_grade < 60;
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

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

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

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

int main() {

	vector<Student_info> vec_students;
	Student_info vec_record;
	string::size_type maxlen = 0;

	cout << "Enter student data using vector data type: " << endl;

	while(read(cin, vec_record)) {
		maxlen = max(maxlen, vec_record.name.size());
		vec_students.push_back(vec_record);
	}

	cin.clear();

	sort(vec_students.begin(), vec_students.end(), compare);

/*	
	for (vector<Student_info>::size_type i = 0; i != vec_students.size(); i++) {
		cout << vec_students[i].name << string(maxlen + 1 - vec_students[i].name.size(), ' ');
		streamsize prec = cout.precision();		
		cout << setprecision(3) << vec_students[i].final_grade << setprecision(prec);

		cout << endl;
	}
*/
	vector<Student_info>::size_type total_students = vec_students.size();
	
	
	double begin = std::clock();
	vector<Student_info> failed_students = extract_fails(vec_students);
	double end = std::clock();

	cout << "Extracting fails for " << total_students << " students took " << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

	cout << "Enter student data for using list data type: " << endl;
	
	list<Student_info> list_students(vec_students.begin(), vec_students.end());
	
	begin = std::clock();
	list<Student_info> list_failed_students = extract_fails(list_students);
	end = std::clock();

	cout << "Extracting fails for " << total_students << " students took " << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

	

	return 0;	

}
