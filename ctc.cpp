#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

class Graph {

public:
    Graph(size_t n) : nrNodes(n) {
        adLs.resize(nrNodes);

    }
    void addEdge(unsigned a, unsigned b) {
        adLs[a].push_back(b);
    }
    const vector<unsigned> &getNeigh(unsigned b) {
        return adLs[b];
    }
    unsigned getNrNodes() {
        return nrNodes;
    }
private:
    vector<vector<unsigned>> adLs;
    size_t nrNodes;
};

class StronglyConnectedFinder {

public:
    StronglyConnectedFinder(Graph g) : graph(g), cnt(1) {
        index.resize(graph.getNrNodes());
        lowlink.resize(graph.getNrNodes());
        inStack.resize(graph.getNrNodes(),false);
    }
    vector<vector<unsigned>> operator()() {
        for(size_t i = 0; i < graph.getNrNodes(); ++i)
            if(!index[i])
                StrongConnect(i);
        return components;
    }
private:
    void StrongConnect(unsigned nd) {
        index[nd] = cnt;
        lowlink[nd] = cnt;
        cnt++;
        ndStk.push(nd);
        inStack[nd] = true;
        for(const auto &v:graph.getNeigh(nd)) {
            if(index[v] == 0) {
                StrongConnect(v);
                lowlink[nd] = min(lowlink[nd],lowlink[v]);
            }
            else if(inStack[v]) {
                lowlink[nd] = min(lowlink[nd],index[v]);
            }
        }

        if(lowlink[nd] == index[nd]) {
            components.push_back(vector<unsigned>());
            unsigned v;
            do {
                v = ndStk.top(); ndStk.pop();
                inStack[v] = false;
                components.back().push_back(v);
            } while(v != nd);
        }
    }
    size_t cnt;
    stack<unsigned> ndStk;
    vector<bool> inStack;
    vector<unsigned> index;
    vector<unsigned> lowlink;
    vector<vector<unsigned>> components;
    Graph graph;
};

int main() {
    size_t n;
    in >> n;
    Graph gr(n);
    size_t m;
    in >> m;
    for(size_t i = 0; i < m; ++i) {
        unsigned a,b;
        in >> a >> b;
        gr.addEdge(a-1,b-1);
    }
    StronglyConnectedFinder solve(gr);
    vector<vector<unsigned>> scc = solve();
    out << scc.size() << '\n';
    for(size_t i = 0; i < scc.size(); ++i) {
        for(size_t j = 0; j < scc[i].size(); ++j)
            out << scc[i][j] + 1 << ' ';
        out << '\n';
    }
}
