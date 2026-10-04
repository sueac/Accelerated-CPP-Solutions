#include "read.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

//counts the number of words per input
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	
	vector<string> words;
	
	cout << "Enter words: " << endl;

	read(cin, words);

	cout << "There are " << words.size() << " words in your sentence." << endl;



	//std::copy(words.begin(), words.end(), std::ostream_iterator<string>(std::cout, " "));








}



