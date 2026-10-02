#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

using std::vector;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::istream;
using std::endl;
using std::rand;
using std::list;

typedef list<string> Rule;
typedef list<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


list<string> split(const string& s) {
	list<string> ret;
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
		list<string> entry = split(line);
		if(!entry.empty())
			//use the category to store the associated rule
			ret[entry.front()].push_back(Rule(next(entry.begin()), entry.end()));
	}
	return ret;
}


bool bracketed(const string& s) {
	return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret) {
	if(!bracketed(word)) {
		ret.push_back(word);
	} else {
		//locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw std::logic_error("empty rule");
		//fetch the set of possible rules
		const Rule_collection& c = it->second;

		int rand = nrand(c.size());

		Rule_collection::const_iterator rule_it = c.begin();

		for (int i = 0; i < rand; ++i) {
			++rule_it;
		}

		const Rule& r = *rule_it;


		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}


list<string> gen_sentence(const Grammar& g) {
	list<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

int main() {
	//generate the sentence
	list<string> sentence = gen_sentence(read_grammar(cin));

	//write the first word, if any
	list<string>::const_iterator it = sentence.begin();
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
