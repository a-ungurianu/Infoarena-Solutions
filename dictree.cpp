#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> cuv;

size_t ndCnt = 0;

void Solve(size_t lvl, size_t st, size_t fn) {
    unsigned nSt = st;

    while(nSt < fn && cuv[nSt].size()<=lvl) nSt++;

    for(size_t i = nSt; i < fn-1; ++i) {
        if(cuv[i][lvl] != cuv[i+1][lvl]) {
            Solve(lvl+1,nSt,i+1);
            ndCnt++;
            nSt = i+1;
        }
    }
    if(nSt < fn) {
        Solve(lvl+1,nSt,fn);
        ndCnt++;
    }
}

int main() {
    size_t n;
    ifstream in("dictree.in");
    in >> n;
    cuv.resize(n);

    for(size_t i = 0; i < n; ++i) {
        in >> cuv[i];
    }
    ofstream out("dictree.out");
    sort(cuv.begin(),cuv.end());

    out.flush();
    Solve(0,0,n);
    out << ndCnt+1 << '\n';
}
