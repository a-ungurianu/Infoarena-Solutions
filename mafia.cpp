#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("mafia.in");
ofstream out("mafia.out");

int main() {
	int t;
	in >> t;
	while(t--) {
		int n,m,x;
		in >> n >> m >> x;
		unsigned long long sum = 0;
		int vx;
		for(int i = 1; i <= n; ++i) {
			int vi;
			in >> vi;
			sum+=vi;
			if(i == x) {
				vx = vi;
			}
		}
		double p = 1;

		if(sum-vx >= m) {

			// This is derived from the formula comb(m,sum-vx)/comb(m,sum)
			double a = sum-m;
			double b = sum;

			for(int i = 0; i < vx; ++i) {
				p*= (a-i)/(b-i);
			}
		}
		out << setprecision(7) <<fixed << 1-p << '\n';
	}

	return 0;
}