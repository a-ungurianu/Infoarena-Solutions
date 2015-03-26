#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ifstream in("euclid3.in");
	ofstream out("euclid3.out");

	unsigned t;
	in >> t;
	for(unsigned i = 0; i < t; ++i) {
		int a,b,c;
		in >> a >> b >> c;
		EuclidResult res = euclid(a,b);
		if((c*1.0f)/res.gcd != c/res.gcd) {
			out << "0 0\n";
		}
		else {
			int rap = c/res.gcd;

			out << res.x*rap << ' ' << res.y*rap << '\n';
		}
	}
	return 0;
}