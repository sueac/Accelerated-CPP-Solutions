#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;



// Overload the << operator for any vector type
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", "; // Add separator between elements
        }
    }
    os << "]";
    return os;
}

bool is_palindrome(string s) {
	string reverse_s(s.rbegin(),s.rend());
	
	return s == reverse_s;

}

vector<string> find_palindrome(vector<string> dict) {
	vector<string> ret;

	for (vector<string>::size_type i = 0; i != dict.size(); ++i) {
		if (is_palindrome(dict[i]))
			ret.push_back(dict[i]);
	}

	return ret;
}

vector<string> longest_words(vector<string> dict) {
	vector<string> longestWords;
	vector<string>::size_type maxlen = 0;

	for (vector<string>::size_type i = 0; i != dict.size(); ++i) {
		if (dict[i].size() > maxlen) {
			maxlen = dict[i].size();
			longestWords.clear();
			longestWords.push_back(dict[i]);
		} else if (dict[i].size() == maxlen) {
		       longestWords.push_back(dict[i]);
	      	}	       
	}

	return longestWords;
}

int main() {
	
	vector<string> words;
	vector<string> palindromes;
	vector<string> longestPalindromes;

	string x;

	while (cin >> x) {
		words.push_back(x);
	}

	palindromes = find_palindrome(words);

	longestPalindromes = longest_words(palindromes);
	
	cout << "The longest palindromes are: " << longestPalindromes << endl;
	
}



