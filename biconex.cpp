#include <fstream>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

struct Edge {
	unsigned a,b;
};

bool operator==(const Edge &lhs, const Edge &rhs) {
	return lhs.a == rhs.a && lhs.b == rhs.b;
}

bool operator!=(const Edge &lhs, const Edge &rhs) {
	return !(lhs == rhs);
}

vector<vector<unsigned>> edges;
vector<bool> visited;
vector<int> parent;
vector<unsigned> dist;
vector<unsigned> low;
stack<Edge> stk;

unsigned count = 0;

vector<unordered_set<unsigned>> components;

void OutputComponent(Edge sent) {
	unordered_set<unsigned> nodes_used;
	Edge e;
	do {
		e = stk.top();
		stk.pop();
		nodes_used.insert(e.a+1);
		nodes_used.insert(e.b+1);
	} while(e != sent);
	components.push_back(nodes_used);
}

void dfs_visit(unsigned u) {
	visited[u] = true;
	count++;
	dist[u] = count;
	low[u] = dist[u];

	for(auto v:edges[u]) {
		if(!visited[v]) {
			stk.push({u,v});
			parent[v] = u;
			dfs_visit(v);
			if(low[v] >= dist[u]) {
				OutputComponent({u,v});
			}
			low[u] = min(low[u],low[v]);
		}
		else if(!(parent[u] == v) && dist[v] < dist[u]) {
			stk.push({u,v});
			low[u] = min(low[u],dist[v]);
		}
	}
}



int main() {

	ifstream in("biconex.in");

	unsigned no_nodes, no_edges;
	in >> no_nodes >> no_edges;
	edges.resize(no_nodes);
	visited.resize(no_nodes,false);
	parent.resize(no_nodes,-1);
	dist.resize(no_nodes);
	low.resize(no_nodes);

	for(int i = 0; i < no_edges; ++i) {
		unsigned a,b;
		in >> a >> b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}

	for(int u = 0; u < no_nodes; ++u) {
		if(!visited[u]) {
			dfs_visit(u);
		}
	}


	ofstream out("biconex.out");

	out << components.size() << '\n';
	for(const auto& comp:components){
		for(auto n:comp) {
			out << n << ' ';
		}
		out << '\n';
	}
}