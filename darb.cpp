#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream in("darb.in");
ofstream out("darb.out");

vector<vector<unsigned>> adjacencyList;
unsigned last,distToLast;

vector<bool> visited;

typedef pair<unsigned,unsigned> BfsNode;

void bfs(unsigned i) {
	visited[i] = true;

    queue<BfsNode> bfsQueue;
	for(bfsQueue.push(BfsNode(i, 0)); !bfsQueue.empty(); bfsQueue.pop()) {
		BfsNode current = bfsQueue.front();
		last = current.first;
		distToLast = current.second;
		for(size_t j = 0; j < adjacencyList[current.first].size(); ++j) {
			if(!visited[adjacencyList[current.first][j]]) {
				visited[adjacencyList[current.first][j]] = true;
				bfsQueue.push(BfsNode(adjacencyList[current.first][j],current.second+1));
			}
		}
	}
}

int main() {
	size_t n;
	in >> n;
	adjacencyList.resize(n);
	visited.resize(n,false);
	for(size_t i = 0; i < n; ++i) {
		unsigned a,b;
		in >> a >> b;
		adjacencyList[a-1].push_back(b-1);
		adjacencyList[b-1].push_back(a-1);
	}

	bfs(0);
	unsigned start = last;
	visited.resize(0);
	visited.resize(n,false);
	bfs(start);

	out << distToLast+1 << '\n';
}
