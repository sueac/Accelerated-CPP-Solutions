
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::isspace;
using std::cout;
using std::cin;
using std::endl;
using std::max;

vector<string> split(const string& s) {
	vector<string> ret;
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

void print_string(const vector<string>& v) {
	
	for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
}

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		maxlen = max(maxlen, v[i].size());
	}

	return maxlen;



}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	ret.push_back(border);

	for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
		ret.push_back("* " + *it + string(maxlen - it -> size(), ' ') + " *");

	}
	
	ret.push_back(border);
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
	vector<string> ret;

	string::size_type width1 = width(left) + 1;

	vector<string>::const_iterator i = left.begin();
	vector<string>::const_iterator j = right.begin();

	while(i != left.end() || j != right.end()) {
		string s;

		if(i != left.end())
			s = *i++;

		s += string(width1 - s.size(), ' ');

		if(j != right.end())
			s += *j++;

		ret.push_back(s);
	}

	return ret;
}





int main() {
	vector<string> left;
	left.push_back("hello");
	left.push_back("my name");
	left.push_back("is Ross");

	vector<string> right;
	
	right.push_back("I am");
	right.push_back("programming");
	right.push_back("in C++!");

	vector<string> frame_left = frame(left);
	vector<string> frame_right = frame(right);

	vector<string> concatenated = hcat(frame_left, frame_right);

	print_string(left);
	print_string(right);
	print_string(frame_left);
	print_string(frame_right);
	print_string(concatenated);


}

