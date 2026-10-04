#include "read.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

//counts the number of words per input
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

typedef vector<string>::size_type vec_sz;

int main() {
	

	vector<string> words;
	
	cout << "Enter words: " << endl;

	read(cin, words);

	sort(words.begin(), words.end());

	vec_sz length = words.size();

	for (vec_sz i = 0; i < length;) {
		int j = i;
		while (j < length && words[j] == words[i]) j++;
		cout << words[i] << ": " << (j - i) << "\n";
		i = j;	
	}



	//std::copy(words.begin(), words.end(), std::ostream_iterator<string>(std::cout, " "));








}



