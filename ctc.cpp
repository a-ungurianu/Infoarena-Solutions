#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

ifstream in ("ctc.in");
ofstream out ("ctc.out");

vector<bool> viz;
vector<bool> viz2;
vector<list<unsigned> > adLs;
vector<list<unsigned> > adLsT;
stack<unsigned> stk;
vector<list<unsigned> > ctc;

int n;

void dfs1(unsigned i) {
	for(const auto &j:adLs[i]) {
		if(!viz[j]) {
			viz[j]=true;
			dfs1(j);
		}
	}
	stk.push(i);
}

void dfs2(unsigned i) {
	for(const auto &j:adLsT[i]) {
		if(!viz2[j]) {
			viz2[j]=true;
			dfs2(j);
		}
	}
	
	ctc.back().push_back(i);
}

int main() {
	in >> n;
	viz.resize(n);
	viz2.resize(n);
	adLsT.resize(n);
	adLs.resize(n);
	
	int m;
	in >> m;
	while(m--) {
		unsigned a,b;
		in >> a >> b;
		adLs[a-1].push_back(b-1);
		adLsT[b-1].push_back(a-1);
	}

	for(unsigned i = 0; i < n; ++i)
		if(!viz[i])
			dfs1(i);
	while(!stk.empty()) {
		int i = stk.top();
		stk.pop();
		if(!viz2[i]) {
			ctc.resize(ctc.size() + 1);
			viz2[i]=true;
			dfs2(i);
		}
	}
	out << ctc.size() << '\n';
	for(const auto s:ctc) {
		for(const auto i:s) {
			out << i+1 << ' ';
		}
		out << '\n';
	}
	return 0;
}
