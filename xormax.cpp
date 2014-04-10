#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

vector<unsigned> v,sum;

void ReadData() {
    ifstream in("xormax.in");
    size_t n;
    in >> n;
    v.resize(n);
    for(size_t i = 0; i < n; ++i)
        in >> v[i];
}

void MakeSumVect() {
    sum.resize(v.size()+1);

    size_t n = v.size();
    sum[0] = 0;
    for(size_t i = 1; i <= n; ++i)
        sum[i] = sum[i-1] ^ v[i-1];
}

typedef pair<size_t,size_t> interval;

interval getMaxPair() {
    size_t n = sum.size();
    size_t mI,mJ;
    unsigned maxSum = 0;
    for(size_t i = 1; i < n; ++i) {
        for(size_t j = 0; j <= i; ++j) {
            //cerr << "[" << j+1 << ":" << i << "] = " << (sum[i]^sum[j]) << ' ' << maxSum << '\n';
            if(maxSum < (sum[i]^sum[j])){
                maxSum = (sum[i]^sum[j]);
                mI = i;
                mJ = j;
            }
        }
    }
    return interval(mJ+1,mI);
}


int main() {
    ReadData();
    MakeSumVect();
    interval mIntv = getMaxPair();

    ofstream out("xormax.out");
    out << (sum[mIntv.second]^sum[mIntv.first-1]) << ' ' << mIntv.first << ' ' << mIntv.second << '\n';
    return 0;
}
