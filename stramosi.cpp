#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream in("stramosi.in");

size_t n,m;

vector<unsigned> parent;

vector<vector<int>> ancestor;

size_t getMSB(size_t nr) {
    for(size_t i = 22; i >= 0; --i)
        if(nr&(1<<i))
            return i;
}

void ReadData() {
    in >> n >> m;
    parent.resize(n+1);
    ancestor.resize(20,vector<int>(n+1,0));
    for(size_t i = 1; i <= n; ++i)
        in >> parent[i];
}

void genAncestor() {
    for(size_t i = 1; i <= n; ++i) {
        ancestor[0][i] = parent[i];
    }
    for(size_t i = 1; i < 20; ++i) {
        for(size_t j = 1; j <= n; ++j) {
            ancestor[i][j] = ancestor[i-1][ancestor[i-1][j]];
        }
    }
}

void SolveQueries() {
    ofstream out("stramosi.out");

    for(size_t i = 0; i < m; ++i) {
        size_t depth;
        unsigned nd;
        in >> nd >> depth;
        while(depth) {
            size_t msb = getMSB(depth);
            nd = ancestor[msb][nd];
            depth ^= 1<<msb;
        }
        out << nd << '\n';
    }
}

int main() {
    ReadData();
    genAncestor();
    SolveQueries();
    return 0;
}
