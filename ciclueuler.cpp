#include <fstream>
#include <vector>
#include <list>

using namespace std;

class Graph {

public:
    Graph();
    vector<unsigned> GetEulerianCycle();
    void AddEdge(unsigned a,unsigned b);
    void SetNNodes(size_t n);
private:
    size_t nNodes;
    vector<list<unsigned>> adLs;
    void RemoveEdge(unsigned a,unsigned b);
};

Graph::Graph() {
    nNodes = 0;
}

void Graph::AddEdge(unsigned a,unsigned b) {
    adLs[a].push_back(b);
    adLs[b].push_back(a);
}

void Graph::SetNNodes(size_t n) {
    nNodes = n;
    adLs.resize(n);
}

void Graph::RemoveEdge(unsigned a,unsigned b) {

}

void ReadData(Graph& g) {
    ifstream in("ciclueuler.in");
    size_t n,m;
    in >> n >> m;
    g.SetNNodes(n);
    for(size_t i = 0; i < m; ++i) {
        unsigned a,b;
        in >> a >> b;
        g.AddEdge(a-1,b-1);
    }
}

int main() {
    Graph g;
    ReadData(g);

    vector<unsigned> cycle = g.GetEulerianCycle();

    for(size_t i = 0,n = cycle.size(); i < n; ++i) {
        cout << cycle[i]+1 << ' ';
    }
}
