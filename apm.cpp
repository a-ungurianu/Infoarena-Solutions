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
	bool operator< (const Edge &e) const {
		return cost < e.cost;
	}
};

int main() {
	size_t n,m;
	in >> n;
	in >> m;
	vector<Edge> edges(m);
	DisjointSets forest(n);

	for(size_t i = 0; i < m; ++i) {
		in >> edges[i].a >> edges[i].b >> edges[i].cost;
	}
	sort(edges.begin(), edges.end());

	vector<Edge> sol;

	auto it = edges.begin();

	while(sol.size() < n-1 && it!=edges.end()) {
		if(!forest.areInSameSet(it->a-1, it->b-1)) {
			sol.push_back(*it);
			forest.unite(it->a-1,it->b-1);
		}
		it++;
	}
	int sum = 0;
	for(size_t i = 0; i < sol.size(); ++i) 
		sum+=sol[i].cost;
	out << sum << '\n';
	out << sol.size() << '\n';
	for(size_t i = 0; i < sol.size(); ++i) {
		out << sol[i].a << ' ' << sol[i].b << '\n';
	}

	return 0;
}
