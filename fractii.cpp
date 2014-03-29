#include <fstream>
#include <vector>

using namespace std;

vector<unsigned> genPhi(unsigned long long n) {
    vector<unsigned> phi;
    phi.resize(n+1);

    for(unsigned long long i = 1; i <= n; i++)
        phi[i]=i;

    for(unsigned long long i = 2; i <= n; i++)
        if(phi[i] == i)
            for(unsigned long long j = i; j <= n; j += i) {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
    return phi;
}

unsigned long long getNumFractions(unsigned long long n) {
    vector<unsigned> phi(genPhi(n));

    unsigned long long numFractions = 1;

    for(unsigned long long i = 2; i <= n; ++i) {
        numFractions += 2 * phi[i];
    }

    return numFractions;
}

int main() {
    unsigned long long n;
    ifstream in("fractii.in");
    in >> n;

    ofstream out("fractii.out");
    out << getNumFractions(n);
}
