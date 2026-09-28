#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main() {
	typedef string::size_type string_sz;
	string word;
	string_sz shortest_size = 0;
       	string_sz longest_size = 0;
	int count = 0;
	
	cout << "Enter a sentence, word by word, followed by eof: " << endl;

	while (cin >> word) {
		if (count == 0) {
			shortest_size = word.size();
			longest_size = word.size();
		} else {
			if (word.size() > longest_size) {
				longest_size = word.size();
			}
			if (word.size() < shortest_size) {
				shortest_size = word.size();
			}
		}
		count++;
	}

		
	cout << "Longest word typed was: " << longest_size << " and shortest word typed was: " << shortest_size << endl;

	//std::copy(array.begin(), array.end(), std::ostream_iterator<string>(std::cout, " "));
	
	//std::copy(count.begin(), count.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;



}
