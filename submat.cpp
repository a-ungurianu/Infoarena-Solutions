#include <iostream>
#include <fstream>
#include <algorithm>
 
using namespace std;
ifstream in ("submat.in");
ofstream out ("submat.out");
 
int n,m;
vector<u_short> v;
 
int main() {
    in >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int t;
            in >> t;
            if(t==0)v[i]++;
            else{
                in.seekg((m-j-1)*2,ios_base::cur);
                break;
            }
        }
    }
    for(int i:v) {
        cerr << i;
    }
    sort(v.begin(), v.end());
    int maxAr = 0;
    for(int i = 0; i < n; ++i) {
        maxAr = max(maxAr,v[i]*(n-i));
    }
    out << maxAr;
    
    return 0;
}
