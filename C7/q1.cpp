#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::pair;
using std::sort;

bool compare(const pair<string,int>& a, const pair<string, int>&  b ) {
	return a.second < b.second;
}

int main() {
	string s;
	map<string, int> counters; //store each word and an associated counter
	
	//read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];


	//copy key-value pairs from map to vector
	vector<pair<string, int> > vec(counters.begin(), counters.end());	
	
	sort(vec.begin(), vec.end(), compare);

	for(const auto& pair : vec) {
		cout << pair.first << ":" << pair.second << "\n";

	}

	//write the words and associated counts
	/*
	for(map<string,int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
	*/
	return 0;
}
