#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
 
using namespace std;
 
ifstream in("retele.in");
ofstream out("retele.out");
 
vector<vector<int>> edges;
 
vector<bool> visited,on_stack;
vector<int> index, lowlink;
vector<vector<int>> components;
stack<int> nodes_visited;
int c_index = 0;
 
void strongconnect(int v) {
    visited[v] = true;
    on_stack[v] = true;
    nodes_visited.push(v);
    index[v] = c_index;
    lowlink[v] = c_index++;
 
    for(int w:edges[v]) {
        if(!visited[w]) {
            strongconnect(w);
            lowlink[v] = min(lowlink[v],lowlink[w]);
        }
        else if(on_stack[w]) {
            lowlink[v] = min(lowlink[v],index[w]);
        }
    }
    if(index[v] == lowlink[v]) {
        components.resize(components.size()+1);
        int w;
        do {
            w = nodes_visited.top();
            nodes_visited.pop();
            on_stack[w] = false;
            components.back().push_back(w);
        } while(w != v);
    }
}

bool sort_lexy(const vector<int> &c1, const vector<int> &c2) {
    return c1[0] < c2[0];
}
 
int main() {
    unsigned n,m;
    in >> n >> m;
    edges.resize(n+1);
    visited.resize(n+1);
    on_stack.resize(n+1);
    index.resize(n+1);
    lowlink.resize(n+1);
 
    for(int i = 0; i < m; ++i) {
        int a,b;
        in >> a >> b;
        edges[a].push_back(b);
    }
 
    for(int i = 1; i <= n; ++i) {
        if(!visited[i])
            strongconnect(i);
    }
 
    for(vector<int> & comp:components) {
        sort(comp.begin(), comp.end());
    }

    sort(components.begin(), components.end(),sort_lexy);
    
    out << components.size() << '\n';

    for(auto comp:components) {
        out << comp.size() << ' ';
        for(int node:comp) {
            out << node << ' ';
        }
        out << '\n';
    }
 
    return 0;
}