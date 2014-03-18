#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;
ifstream in("ciclueuler.in");
ofstream out("ciclueuler.out");

class Graph {

public:
	Graph(size_t n): noNodes(n),_isConnected(-1) {adLs.resize(n);}

	void addEdge(unsigned a,unsigned b) {
		adLs[a].push_back(b);
		adLs[b].push_back(a);
		if(_isConnected == 0) _isConnected = -1;
	}

	bool isConnected() {
		if(_isConnected!=-1) {
			if(_isConnected)
				return true;
			return false;
		}

		vector<bool> passed;
		passed.resize(noNodes);
		connDFS(0,passed);
		for(size_t i = 0; i < noNodes; ++i) {
			if(!passed[i]){
				_isConnected = 0;
				return false;
			}
		}
		return true;
	}

	bool isEulerian() {
		if(!isConnected()) return false;
		for(size_t i = 0; i < noNodes; ++i) {
			if(adLs[i].size()%2) return false;
		}
		return true;
	}

	vector<unsigned> getEulerCycle(unsigned node) {
		stack<unsigned> stk;
		vector<unsigned> cycle;
		do {
			euler(node,stk);
			node = stk.top();
			stk.pop();
			cycle.push_back(node);
		}while(!stk.empty());

		return cycle;
	}
private:
	void connDFS(unsigned nd,vector<bool> &passed) {
		passed[nd] = true;
		for(const auto &nd2:adLs[nd]) {
			if(!passed[nd2])
				connDFS(nd2,passed);
		}
	}

	void euler(unsigned node, stack<unsigned> &stk) {
		while(true) {
			if(adLs[node].empty()) 
				break;
			unsigned to = adLs[node].front();
			stk.push(node);
			adLs[node].pop_front();
			adLs[to].erase(find(adLs[to].begin(), adLs[to].end(), node));
			node = to;
		}
	}

	int _isConnected;
	vector<list<unsigned>> adLs;
	size_t noNodes;
};

int main() {
	size_t n,m;
	in >> n >> m;
	Graph G(n);
	for(size_t i = 0; i < m; ++i) {
		unsigned a,b;
		in >> a >> b;
		G.addEdge(a-1,b-1);
	}
	if(G.isEulerian()){

		vector<unsigned> cycle = G.getEulerCycle(0);

		for(size_t i = 0; i < cycle.size(); ++i) {
	        out << cycle[i]+1 << ' ';
		}
		out << '\n';
	}
	else 
		out << "-1\n";
}
