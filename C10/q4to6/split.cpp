#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include "String_list.h"

using std::string;
using std::vector;
using std::isspace;
using std::cout;
using std::cin;
using std::endl;


String_list split(const string& s) {
	String_list ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//ignore leading blanks
		//invariant: characters in range [original i, current i] are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;
		//find end of next word
		string_size j = i;
		//invariant: none of the characters in range [original j, current j) is a space 
		while (j != s.size() && !isspace(s[j]))
			++j;
		if (i != j) {
			//copy from s starting from i to j
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return ret;
}

int main() {

	String_list list;
	
	string x;

	getline(cin, x);

	list = split(x);

	for (String_list::iterator it = list.begin(); it != list.end(); ++it) {
		cout << *it << endl;

	}


}

