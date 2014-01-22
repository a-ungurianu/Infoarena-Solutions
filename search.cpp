#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
ifstream in("search.in");
ofstream out("search.out");

vector<vector<unordered_map<char,size_t>>> nextPos;

vector<stack<size_t>> lastPos;

stack<size_t> sols;

size_t m;

void AddWord(size_t wordInd, string s) {
	vector<unordered_map<char,size_t>> wordData;
	wordData.resize(s.size());
	for(int i = s.size()-1; i >= 0; --i) {
		for(int j = i; j >= 0; --j) {
			wordData[j][s[i]] = i;
		}
	}
	nextPos[wordInd] = wordData;
}

size_t AddLetter(char c) {
	size_t curSol = sols.top();
	for(size_t i = 0; i < nextPos.size(); ++i) {
		if(nextPos[i][lastPos[i].top()].count(c)) {
			lastPos[i].push(nextPos[i][lastPos[i].top()][c]);
		}
		else curSol--;
	}
	sols.push(curSol);
	return sols.top();
}

size_t RemoveLetter() {
	for(size_t i = 0; i < lastPos.size(); ++i)
		lastPos[i].pop();
	sols.pop();
	return sols.top();
}

void ReadData() {
	size_t n;
	in >> n >> m;
	nextPos.resize(n);
	lastPos.resize(n);
	for(size_t i = 0; i < n; ++i)
		lastPos[i].push(0);
	sols.push(n);
	string s;
	
	for(size_t i = 0; i < n; ++i){
		in >> s;
		AddWord(i,s);
	}
}

void AnswerQueries() {
	for(size_t i = 0; i < m; ++i) {
		char c;
		in >> c;
		if(c == '-') 
			out << RemoveLetter() << '\n';
		else 
			out << AddLetter(c) << '\n';
	}
}

int main() {
	ReadData();
	AnswerQueries();
}
