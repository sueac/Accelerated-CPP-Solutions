#include <string>
#include <map>
#include <iostream>
#include <vector>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::istream;

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



//find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split) {
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while(getline(in, line)) {
		++line_number;

		//break the input line into words
		vector<string> words = find_words(line);

		map<string, int> seen;

		//remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
			++seen[*it];
			if (seen[*it] == 1) {
				ret[*it].push_back(line_number);
			}
		}
	}
	return ret;
}

int main() {
	//call xref using split by default
	map<string, vector<int> > ret = xref(cin);
	
	//write the results
	
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
		//write the word
		if (it->second.size() > 1) {
			cout << it->first << " occurs on lines: ";
		} else {
			cout << it->first << " occurs on line: ";
		}
		
		//followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; //write the first number

		++line_it;
		//write the rest of the line numbers, if any
		while(line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}

	return 0;
}
