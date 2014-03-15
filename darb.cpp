#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream in("darb.in");
ofstream out("darb.out");

vector<vector<unsigned>> adLs;
unsigned last,distToLast;

vector<bool> viz;

typedef pair<unsigned,unsigned> BfsNode;

void bfs(unsigned i) {
	viz[i] = true;
	queue<BfsNode> Q;
	for(Q.push(BfsNode(i,0));!Q.empty(); Q.pop()) {
		BfsNode c = Q.front();
		last = c.first;
		distToLast = c.second;
		for(size_t j = 0; j < adLs[c.first].size(); ++j) {
			if(!viz[adLs[c.first][j]]) {
				viz[adLs[c.first][j]] = true;
				Q.push(BfsNode(adLs[c.first][j],c.second+1));
			}
		}
	}
}

int main() {
	size_t n;
	in >> n;
	adLs.resize(n);
	viz.resize(n,false);
	for(size_t i = 0; i < n; ++i) {
		unsigned a,b;
		in >> a >> b;
		adLs[a-1].push_back(b-1);
		adLs[b-1].push_back(a-1);
	}

	bfs(0);
	unsigned start = last;
	viz.resize(0);
	viz.resize(n,false);
	bfs(start);
	unsigned end = last;

	out << distToLast+1 << '\n';
}
