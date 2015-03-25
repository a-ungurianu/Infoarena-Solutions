#include <fstream>

using namespace std;

typedef long long BigUnsigned;

BigUnsigned X[1002][1002];

const unsigned mod = 666013;

BigUnsigned fast_pow(BigUnsigned b, BigUnsigned e) {
	if(e == 0) return 1;
	if(e == 1) return b%mod;
	if(e % 2 == 0) {
		return fast_pow((b*b)%mod,e/2) % mod;
	}
	else {
		return (b * fast_pow((b*b)%mod,e/2)) % mod;
	}
}


void make_X(unsigned n) {
	for(unsigned i = 1; i <= n; ++i) {
		X[i][1] = X[1][i] = fast_pow(2,i);			
	}

	for(unsigned i = 2; i <= n; ++i) {
		for(unsigned j = 2; j <= n; ++j) {
			X[i][j] = (2*X[i][j-1]%mod + 2*X[i-1][j]%mod - 2*X[i-1][j-1]%mod)%mod;
		}
	}
}

int main() {
	ifstream in("retea3.in");
	BigUnsigned n,m;
	in >> m >> n;
	make_X(n);

	ofstream out("retea3.out");
	out << (fast_pow(X[n][n],m-1) + mod)%mod;

	return 0;
}