#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in ("orase.in");
ofstream out ("orase.out");

struct oras {
    int l,d;
    bool operator<(const oras& rhs) const {
        return (d < rhs.d);
    }
};

int n,m;

vector<oras> v;

int main() {

    in >> m >> n;

    v.resize(n);
    for(int i = 0; i < n; ++i)
        in >> v[i].d >> v[i].l;

    sort(v.begin(),v.end());

    int curMax = v[0].l-v[0].d;
    int curMaxInd = 0;
    int maxDist = 0;

    for(int i = 1; i < n; ++i) {
        maxDist = max(maxDist,v[i].l+v[i].d+v[curMaxInd].l-v[curMaxInd].d);
        if(v[i].l-v[i].d > curMax) {
            curMax = v[i].l-v[i].d;
            curMaxInd = i;
        }
    }

    out << maxDist << '\n';

    return 0;
}
