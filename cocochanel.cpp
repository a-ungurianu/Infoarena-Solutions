#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::vector;
size_t getStartPos(unsigned cocos, const vector<unsigned> &gaini) {
    using std::upper_bound;
    return upper_bound(gaini.begin(), gaini.end(), cocos-1) - gaini.begin();
}

unsigned nrPrietene(unsigned cocos, const vector<unsigned> &gaini) {
    unsigned prietene = 0;

    for (size_t i = getStartPos(cocos, gaini); i < gaini.size(); ++i) {
        if (cocos <= gaini[i]) {
            cocos*=2;
            prietene++;
        }
    }
    return prietene;
}

int main() {
    using std::ifstream;
    ifstream in("cocochanel.in");

    size_t nCocosi, nGaini;
    in >> nCocosi >> nGaini;

    vector<unsigned> cocosi(nCocosi);
    vector<unsigned> gaini(nGaini);

    for (unsigned &cocos:cocosi) {
        in >> cocos;
    }

    for (unsigned &gaina:gaini) {
        in >> gaina;
    }

    using std::sort;
    sort(gaini.begin(), gaini.end());

    using std::ofstream;
    ofstream out("cocochanel.out");

    for(const unsigned &cocos:cocosi) {
        out << nrPrietene(cocos, gaini) << '\n';
    }

    return 0;
}