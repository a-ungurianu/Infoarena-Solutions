#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

ifstream in("evaluare.in");
ofstream out("evaluare.out");

map<char,unsigned> prec{{'+',0},{'-',0},{'*',1},{'/',1},{'e',100},{')',100}};

struct Token {
	char type;
	int value;
};

ostream& operator<<(ostream &os, const Token &t) {
	if(t.type == 'n') {
		os << "n=" << t.value;
	}
	else {
		os << t.type;
	}

	return os;
}

Token next_token(string::iterator &it) {
	switch(*it) {
		case '+':
		case '*':
		case '-':
		case '/': 
		case '(':
		case ')':
			return {*it++,0};
	}

	int nr = 0;
	while('0' <= *it && *it <= '9') {
		nr = nr*10 + (*it-'0');
		it++;
	}
	return {'n',nr};
}

int op(int a, int b, char op) {
	switch(op) {
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}

	cerr << "[op] Expected operator, got " << op << '\n';
}

int eval(vector<Token>::iterator &it,unsigned lvl) {
	int res;
	if(lvl == 2) {
		if(it->type == '(') {
			++it;
			res = eval(it,0);
			++it;
		}
		else {
			if(it->type != 'n') {
				cerr << "[eval] Expected number, got " << it->type << '\n';
			}
			res = it->value;
			it++;
		}
	}
	else {
		res = eval(it,lvl+1);
		while(prec[it->type] == lvl) {
			char type = it->type;
			it++;
			res = op(res,eval(it,lvl+1),type);
		}
	}
	return res;
}

vector<Token> tokenize(string s) {
	vector<Token> tokens;
	auto it = s.begin();
	while(it < s.end()) {
		tokens.push_back(next_token(it));
	}

	tokens.push_back({'e',0});

	return move(tokens);
}

int main() {
	string s;
	in >> s;

	vector<Token> tokens = tokenize(s);

	// for(Token t:tokens) {
	// 	cout << t << ' ';
	// }

	auto it = tokens.begin();

	out << eval(it,0);

	return 0;
}