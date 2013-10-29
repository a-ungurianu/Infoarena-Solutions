#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

ifstream in("sortaret.in");
ofstream out("sortaret.out");

vector<list<unsigned>> adLists;
vector<unsigned> sol;
vector<bool> visited;

int n;

void topsort(int i) {
	visited[i]=true;
	for(auto j:adLists[i]) {
		if(!visited[j])
			topsort(j);
	}
	sol.push_back(i);
}

int main() {
	int m;
	in >> n >> m;
	adLists.resize(n+1);
	visited.resize(n+1);
	for(int i = 0; i < m; ++i) {
		int a,b;
		in >> a >> b;
		adLists[a].push_front(b);
	}

	for(int i = 1; i <= n; ++i) {
		if(!visited[i]){
			topsort(i);
		}
	}
	for(int i = sol.size()-1; i>=0; --i) {
		out << sol[i] << ' ';
	}
}
