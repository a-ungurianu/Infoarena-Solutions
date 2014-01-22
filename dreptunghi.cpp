#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("dreptunghi.in");
ofstream out("dreptunghi.out");

int main() {
	unsigned n,m;
	in >> m >> n;

	unsigned sol = 0;

	while(n && m) {
		if(m < n) swap(m,n);
		sol+=(m/n)*n;
		m = m % n;
	}
	out << sol << '\n';
}
