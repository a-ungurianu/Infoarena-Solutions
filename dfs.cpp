#include <iostream>
#include <fstream>
#include <vector>
#include <forward_list>

using namespace std;
ifstream in ("dfs.in");
ofstream out ("dfs.out");

vector<unsigned int> viz;
vector<forward_list<unsigned int> >adLs;

void dfs(unsigned int nod, unsigned int cpId) {
	viz[nod]=cpId;
	for(const auto &i:adLs[nod]) {
		if(!viz[i]){
			dfs(i,cpId);
		}
	}
}

int main() {
	int n;
	in >> n;
	viz.resize(n+1);
	adLs.resize(n+1);
	int m;
	in >> m;
	for(int i = 0; i < m; ++i) {
		int a,b;
		in >> a >> b;
		adLs[a].push_front(b);
		adLs[b].push_front(a);
	}
	bool hasFreeNodes = false;
	int cnt = 1;

	int i = 1;
	do {
		for(; i <= n; ++i) {
			if(!viz[i]) {
				hasFreeNodes = true;
				break;
			}
		}
		if(i > n) break;
		dfs(i,cnt++);
	} while(hasFreeNodes);
	out << cnt-1 << '\n';
	return 0;
}
