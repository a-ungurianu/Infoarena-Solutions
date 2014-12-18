#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in("apm.in");
ofstream out("apm.out");

class DisjointSets {

	struct Node {
		unsigned parent;
		unsigned rank;
	};

public:
	DisjointSets(size_t n) {
		forest.resize(n);
		for(size_t i = 0; i < n; ++i) {
			forest[i].parent = i;
			forest[i].rank = 0;
		}
	}

	bool areInSameSet(unsigned a, unsigned b) {
		return FindRep(a) == FindRep(b);
	}

	void unite(unsigned a, unsigned b) {
		unsigned aR = FindRep(a);
		unsigned bR = FindRep(b);
		if(forest[aR].rank > forest[bR].rank)
			forest[bR].parent = aR;
		else if(forest[aR].rank < forest[bR].rank)
			forest[aR].parent = bR;
		else {
			forest[aR].parent = bR;
			forest[bR].rank++;
		}
	}

private:
	unsigned FindRep(unsigned i) {
		if(forest[i].parent != i) {
			forest[i].parent = FindRep(forest[i].parent);
		}
		return forest[i].parent;
	}

	vector<Node> forest;
};

struct Edge {
	unsigned a,b;
	int cost;
};

int main() {
	size_t n,m;
	in >> n;
	in >> m;
	DisjointSets forest(n);
    vector<Edge> edges(m);

	for(size_t i = 0; i < m; ++i) {
		in >> edges[i].a >> edges[i].b >> edges[i].cost;
	}

	sort(edges.begin(), edges.end(),[] (Edge e1, Edge e2){ return e1.cost < e2.cost; });

	vector<Edge> sol;

    for(Edge edge:edges)
    {
        if(sol.size() >= n-1) break;

        if(!forest.areInSameSet(edge.a - 1, edge.b - 1)) {
			sol.push_back(edge);
			forest.unite(edge.a - 1,edge.b - 1);
		}
	}

	int totalCost = 0;
	for(size_t i = 0; i < sol.size(); ++i)
		totalCost+=sol[i].cost;

    out << totalCost << '\n';
	out << sol.size() << '\n';

    for(size_t i = 0; i < sol.size(); ++i) {
		out << sol[i].a << ' ' << sol[i].b << '\n';
	}

	return 0;
}
