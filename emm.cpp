#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream in("emm.in");
ofstream out("emm.out");

struct Token {
	char type;
	int value;
};

const unsigned max_lvl = 1;
map<char,unsigned> prec{{'m',0},{'M',0},{')',100},{'e',100}};

Token next_token(string::const_iterator &it) {
	switch(*it) {
		case 'M':
		case 'm':
		case '(':
		case ')':
			return {*it++,0};
	}

	int res = 0;
	while('0' <= *it && *it <= '9') {
		res = res*10 + (*it-'0');
		it++;
	}
	return {'n',res};
}

vector<Token> tokenize(const string &s) {
	vector<Token> tokens;
	auto it = s.cbegin();

	while(it < s.cend()) {
		tokens.push_back(next_token(it));
	}

	tokens.push_back({'e',0});

	return tokens;
}

int eval(int a, int b, char op) {
	switch(op) {
		case 'M':
			return max(a,b);
		case 'm':
			return min(a,b);
	}

	cerr << "[eval] Expected operator, got " << op << '\n';
}

int expr(vector<Token>::iterator &it, unsigned lvl) {
	int res = 0;
	if(lvl == max_lvl) {
		if(it->type == '(') {
			it++;
			res = expr(it,0);
			it++;
		}
		else {
			if(it->type != 'n') {
				cerr << "[expr] Expected number, got " << it->type << '\n';
			}
			res = it->value;
			it++;
		}
	}
	else {
		res = expr(it,lvl+1);
		while(prec[it->type] == lvl) {
			char op = it->type;
			it++;
			res = eval(res,expr(it,lvl+1),op);
		}
	}
	return res;
}

int main() {
	string s;

	in >> s;

	vector<Token> tokens = tokenize(s);	

	auto it = tokens.begin();

	out << expr(it,0) << '\n';

	return 0;
}