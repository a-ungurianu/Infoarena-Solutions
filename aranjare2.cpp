#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in ("aranjare2.in");
ofstream out ("aranjare2.out");

int n;
vector<unsigned> x;
vector<unsigned> inv;

int main() {
	in >> n;
	x.resize(2*n+2);
	inv.resize(2*n+2);
	for(int i = 1; i <= n; ++i) {
		x[i]=2*i-1;
		x[n+i]=2*i;
		inv[2*i-1]=i;
		inv[2*i]=n+i;
	}

	for(int i = 1; i <= 2*n; ++i) {
		if(x[i]!=i) {
			
			out << i << ' ' <<inv[i] << '\n';

			unsigned t = x[i];
			swap(x[i],x[inv[i]]);
			swap(inv[i],inv[t]);
		}
	}

}
