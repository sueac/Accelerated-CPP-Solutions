#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Student_info_pf.h"


using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;

int main() {
	vector<Student_info_pf> students;
	Student_info_pf record;
	string::size_type maxlen = 0;

	while(record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info_pf>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		if (students[i].grade() > 60) {
			cout << "P" << endl;
		} else {
			cout << "F" << endl;
		}	
	}

}
