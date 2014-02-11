#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <set>

using namespace std;

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

typedef vector<unsigned> vec_u;
typedef pair<unsigned,unsigned> pair_u;
typedef vector<pair_u> vec_pair_u;

const unsigned INF = numeric_limits<unsigned>::max();

class Graph {

public:
	Graph(size_t n) :
		nNodes(n)
	{
		adLs.resize(n);
	}

	void addEdge(unsigned from, unsigned to, unsigned cost) {
		adLs[from].push_back(pair_u(to,cost));
	}

	vec_u fromOnetoAll(unsigned s) {
		vec_u dist(nNodes,INF);
		set<pair_u> Q;
		Q.insert(pair_u(0,s));

		while(!Q.empty()) {
			pair_u top = *Q.begin();
			Q.erase(Q.begin());
			unsigned v1 = top.second;

			for(vec_pair_u::const_iterator it = adLs[v1].begin(); it != adLs[v1].end(); ++it) {
				unsigned v2 = it->first;
				unsigned cost = it->second;
				if(dist[v2] > dist[v1] + cost) {
					if(dist[v2] != INF)
						Q.erase(Q.find(pair_u(dist[v2],v2)));
					dist[v2] = dist[v1] + cost;
					Q.insert(pair_u(dist[v2],v2));
				}
			}
		}
		for(size_t i = 0; i < nNodes; ++i) {
			if(dist[i]==INF)dist[i] = 0;
			else dist[i]++;
		}
		return dist;
	}
	size_t getNNodes() {
		return nNodes;
	}
private:
	vector<vec_pair_u> adLs;
	size_t nNodes;
};

int main() {
	size_t n;
	in >> n;

	Graph graph(n);

	size_t m;
	in >> m;
	for(size_t i = 0; i < m; ++i) {
		unsigned a,b,cost;
		in >> a >> b >> cost;
		graph.addEdge(a-1,b-1,cost);
	}

	vec_u dists = graph.fromOnetoAll(0);
	for(size_t i = 1; i < graph.getNNodes(); ++i) {
		out << dists[i] << ' ';
	}
	return 0;
}
