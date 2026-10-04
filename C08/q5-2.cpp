#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::istream;
using std::endl;
using std::rand;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


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

int nrand(int n) {
	if (n <= 0 || n > RAND_MAX) {
		throw std::domain_error("Argument to nrand is out of range");
	}

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand()/bucket_size;
	while(r >= n);
	
	return r;
}


Grammar read_grammar(istream& in) {
	Grammar ret;
	string line;

	//read the input
	
	while(getline(in, line)) {
		//split the input into words
		vector<string> entry = split(line);
		if(!entry.empty())
			//use the caregory to store the associated rule
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}


bool bracketed(const string& s) {
	return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}

template <class Out>
void gen_aux(const Grammar& g, const string& word, Out os) {
	if(!bracketed(word)) {
		*os++ = word;
	} else {
		//locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw std::logic_error("empty rule");
		//fetch the set of possible rules
		const Rule_collection& c = it->second;

		//from which we select one at random
		const Rule& r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, os);
	}
}

template <class Out>
void gen_sentence(const Grammar& g, Out os) {
	gen_aux(g, "<sentence>", os);
}

int main() {
	srand(static_cast<unsigned>(time(nullptr)));

	//generate the sentence
	vector<string> sentence;
       	gen_sentence(read_grammar(cin), back_inserter(sentence));

	//write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
	if(!sentence.empty()){
		cout << *it;
		++it;
	}
	//write the rest of the words, each preceded by a space
	while(it != sentence.end()) {
		cout << " " << *it;
		++it;
	}
	cout << endl;
	return 0;
}
