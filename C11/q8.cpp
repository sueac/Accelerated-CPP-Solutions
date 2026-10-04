#include <iostream>
#include <string>
#include "List.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	List<string> l;
	l.push_back("B");
	l.push_back("C");
	l.push_back("A");

	for (List<string>::iterator it = l.begin(); it != l.end(); ++it) {
		cout << *it << endl;
	}

	List<string>::iterator it = l.begin();
	++it;
	it = l.insert(it, "x");
	it = l.erase(it);
	cout << *it << ' ' << l.size() << '\n';

	List<string>::iterator r = l.end();
	while (r != l.begin()) {
		--r;
		cout << *r << endl;
	}

	List<string> copy(l);
	copy.pop_back();
	cout << l.size() << ' ' << copy.size() << '\n'; //3 2
	
	List<string> empty;
	try {
		empty.pop_front();
	} catch (std::domain_error& e) {
		cout << "caught: " << e.what() << '\n';
	}
}
