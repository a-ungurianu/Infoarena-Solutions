#include <fstream>
#include <vector>

using namespace std;

const vector<unsigned> val{1,5,10,50,100,500};
vector<unsigned long long> cnt(6,0);

bool canBeGiven(unsigned long long s) {
    vector<unsigned long long> tmp = cnt;
    for(int bI = 5; bI >= 0 && s != 0; bI--) {
        unsigned nB = s/val[bI];
        if(nB <= cnt[bI]) {
            cnt[bI] -= nB;
            s-=nB*val[bI];
        }
        else {
            s-=cnt[bI]*val[bI];
            cnt[bI] = 0;
        }
    }
    if(s==0)
        return true;
    cnt = tmp;
    return false;
}

int main() {
    ifstream in("bancomat.in");
    size_t t;
    in >> t;

    ofstream out("bancomat.out");
    while(t--) {
        for(size_t i = 0; i < 6; ++i)
            in >> cnt[i];
        size_t n;
        in >> n;
        bool canGiveAll = true;
        while(n--) {
            unsigned long long s;
            in >> s;
            canGiveAll = canGiveAll && canBeGiven(s);
        }
        out << (canGiveAll?"YES":"NO") << '\n';
    }

}
