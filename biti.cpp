#include <fstream>
#include <vector>

using namespace std;

unsigned k;
const unsigned n = 2;

void ReadData() {
    ifstream in("biti.in");
    in >> k;
}

vector<unsigned> a;
vector<unsigned> seq;

void db(unsigned t, unsigned p) {
    if(t > k) {
        if(k % p == 0) {
            for(size_t j = 1; j <= p; ++j) {
                seq.push_back(a[j]);
            }
        }
    }
    else {
        a[t] = a[t - p];
        db(t+1,p);
        for(size_t j = a[t - p] + 1; j < n; ++j) {
            a[t] = j;
            db(t+1,t);
        }
    }
}

void genDeBrujinSeq() {
    a.resize(n*k,0);
    db(1,1);
}

void printSeq() {
    ofstream out("biti.out");
    out << seq.size()+ k - 1 << '\n';

    for(size_t i = 0, n = seq.size(); i < n; ++i)
        out << seq[i];

    for(size_t i = 0; i < k-1; ++i)
        out << 0;
    out << '\n';
}

int main() {
    ReadData();
    genDeBrujinSeq();
    printSeq();
    return 0;
}
