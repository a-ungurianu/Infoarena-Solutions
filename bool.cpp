#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream in("bool.in");
ofstream out("bool.out");

bool variables[30];

bool True = true;
bool False = false;

struct Token {
	string type;
	bool *value;
};

ostream& operator<<(ostream &os, const Token &t) {
	os << t.type;
	if(t.type == "VAR") {
		os << ":";
		if(*t.value) {
			os << "True";
		}
		else {
			os << "False";
		}
	}
	return os;
}

string::iterator eos;

bool operator==(const string::iterator &it, const string &s) {
	for(int i = 0; i < s.size(); ++i) {
		if(it+i >= eos || *(it+i) != s[i]) {
			return false;
		}
	}
	return true;
}

const unsigned max_lvl = 3;
map<string,unsigned> prec{{"AND",1},{"OR",0},{"NOT",2},{"EOE",100},{")",100}};

Token next_token(string::iterator &it) {
	while(*it == ' ') {
		it++;
	}

	if(it == "(" || it == ")") {
		return {string() + *it++};
	}

	if(it == "OR") {
		it+=2;
		return {"OR"};
	}
	
	if(it == "AND") {
		it+=3;
		return {"AND"};
	}

	if(it == "NOT") {
		it+=3;
		return {"NOT"};
	}

	if(it == "TRUE") {
		it+=4;
		return {"VAR",&True};
	}
	if(it == "FALSE") {
		it+=5;
		return {"VAR",&False};
	}
	char var = *it;
	it++;
	if('A' <= var && var <= 'Z')
		return {"VAR",&variables[var-'A']};
}

struct Node {
	string type;
	bool *value;
	Node *left;
	Node *right;
};

vector<Token> tokenize(string &s) {
	vector<Token> tokens;
	auto it = s.begin();
	eos = s.end();

	while(it < s.end()) {
		tokens.push_back(next_token(it));
	}
	tokens.push_back({"EOE"});

	return tokens;
}

Node* expr(vector<Token>::iterator &it, unsigned lvl) {
	Node* res;

	if(lvl == max_lvl) {
		if(it->type == "(") {
			it++;
			res = expr(it,0);
			it++;
		}
		else {
			if(it->type != "VAR") {
				cerr << "[expr] Expected variable, got " << it->type << '\n';
			}
			bool *val = it->value;
			it++;
			res = new Node{"VAR",val};
		}
	}
	else if(lvl == 2) {
		if(it->type != "NOT") {
			res = expr(it,lvl+1);
		}
		else {
			res = new Node{"NOT",nullptr,expr(++it,lvl)};
		}
	}
	else {
		res = expr(it,lvl+1);
		while(prec[it->type] == lvl) {
			res = new Node{it->type,nullptr,res,expr(++it,lvl+1)};
		}
	}

	return res;
}


bool eval(Node *node) {
	if(node->type == "VAR") {
		return *node->value;
	}
	if(node->type == "NOT") {
		return !eval(node->left);
	}
	if(node->type == "AND") {
		return eval(node->left) && eval(node->right);
	}
	if(node->type == "OR") {
		return eval(node->left) || eval(node->right);
	}
}

int main() {
	string s;
	getline(in,s);

	vector<Token> tokens = tokenize(s);

	auto it = tokens.begin();
	Node* root = expr(it,0);

	unsigned n;
	in >> n;
	for(int i = 0; i < n; ++i) {
		char c;
		in >> c;
		variables[c-'A'] = !variables[c-'A'];
		out << eval(root);
	}

	return 0;
}