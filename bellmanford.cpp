#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream in("bellmanford.in");
ofstream out("bellmanford.out");

struct Node {
	Node(unsigned id,short cost) : id(id),cost(cost)
		{}
	unsigned id;
	short cost;
};

vector<int> BellFord(const vector<vector<Node>> &adLs, unsigned source) {
	queue<unsigned> q;
	vector<int> dist(adLs.size(),int(1<<30));
	dist[source] = 0;


	vector<unsigned> updateCnt(adLs.size(),0);

	for(q.push(source); !q.empty(); q.pop()) {
		unsigned curNd = q.front();
		for(size_t i = 0; i < adLs[curNd].size(); ++i) {
			if(dist[curNd] + adLs[curNd][i].cost < dist[adLs[curNd][i].id]) {
				dist[adLs[curNd][i].id] = dist[curNd] + adLs[curNd][i].cost;
				updateCnt[adLs[curNd][i].id]++;

				q.push(adLs[curNd][i].id);

				if(updateCnt[adLs[curNd][i].id] > adLs.size()) {
					dist.resize(adLs.size()+1);
					return dist;
				}
			}
		}
	}
	return dist;

}

int main() {
	vector<vector<Node>> adLs;
	size_t n,m;
	in >> n >> m;
	adLs.resize(n);

	for(size_t i = 0; i < m; ++i) {
		unsigned a,b;
		short c;
		in >> a >> b >> c;
		adLs[a-1].push_back(Node(b-1,c));
	}

	vector<int> dist = BellFord(adLs,0);

	if(dist.size() > adLs.size()) {
		out << "Ciclu negativ!\n";
	}
	else {
		for(size_t i = 1; i < n; ++i) {
			out << dist[i] << ' ';
		}
	}
}
