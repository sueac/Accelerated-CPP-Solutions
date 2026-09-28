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
	vector<string> array;
	vector<int> count;
	typedef vector<string>::size_type vec_sz;
	string word;
	vec_sz size;
	bool flag = false;
	int flag_index;

	cout << "Enter a sentence, word by word, followed by eof: " << endl;

	while (cin >> word) {
		//check if it is in array
		size = array.size();
		for (int i = 0; i < size; i++) {
			if (array[i] == word) {
				flag = true;
				flag_index = i;
			}
		}
		if (flag) { //object is not new
			count[flag_index] += 1;
			flag = false;
			
		} else {  //object is new
			array.push_back(word);
			count.push_back(1);

		}	

	}

	for (int i = 0; i < array.size(); i++) {
		cout << "Word(" << array[i] << ") and count: " << count[i] << endl;

	}

	//std::copy(array.begin(), array.end(), std::ostream_iterator<string>(std::cout, " "));
	
	//std::copy(count.begin(), count.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;



}
