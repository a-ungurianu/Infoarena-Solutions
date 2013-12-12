#include <fstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
ifstream in("paranteze2.in");
ofstream out("paranteze2.out");

string sir;
stack<unsigned> stk;
vector<unsigned> pd;
vector<unsigned> nxt;

int main() {
	in >> sir;

	pd.resize(sir.size());
	nxt.resize(sir.size());

	for(size_t i = 0,n = sir.size(); i < n; ++i) {
		if(sir[i]=='(') {
			stk.push(i);
		}
		else if(!stk.empty()&&sir[stk.top()]=='(') {
			nxt[stk.top()]=i+1;
			stk.pop();
		}	
	}

	unsigned long long sol = 0;
	for(int i = nxt.size()-1; i >= 0; --i) {
		if(nxt[i]) {
			pd[i]= 1 + pd[nxt[i]];
			sol += pd[i];
		}
	}

	out << sol << '\n';

	return 0;
}
