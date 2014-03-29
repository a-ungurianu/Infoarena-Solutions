#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

size_t n;

vector<unsigned> parent;
vector<unsigned> K;

vector<vector<unsigned>> ancestor;

size_t getMSB(size_t nr) {
    for(size_t i = 22; i >= 0; --i)
        if(nr&(1<<i))
            return i;
}

void ReadData() {
    ifstream in("cerere.in");
    in >> n;
    parent.resize(n+1);
    ancestor.resize(18,vector<unsigned>(n+1,0));
    K.resize(n+1);
    for(size_t i = 1; i <= n; ++i)
        in >> K[i];
    for(size_t i = 1; i < n; ++i) {
        unsigned p,c;
        in >> p >> c;
        parent[c] = p;
    }
}

void genAncestor() {
    for(size_t i = 1; i <= n; ++i) {
        ancestor[0][i] = parent[i];
    }
    for(size_t i = 1; i < 18; ++i) {
        for(size_t j = 1; j <= n; ++j) {
            ancestor[i][j] = ancestor[i-1][ancestor[i-1][j]];
        }
    }
}

unsigned getAncestor(unsigned nd, unsigned depth) {
        while(depth) {
            size_t msb = getMSB(depth);
            nd = ancestor[msb][nd];
            depth ^= 1<<msb;
        }
        return nd;
}

void Solve() {
    ofstream out("cerere.out");
    for(size_t i = 1; i <= n; ++i) {
        unsigned mok = i;
        size_t cnt = 0;

        while(K[mok] != 0) {
            mok = getAncestor(mok,K[mok]);
            cnt++;
        }
        out << cnt << ' ';
    }
    out << '\n';
}

int main() {
    ReadData();
    genAncestor();
    Solve();
    return 0;
}
