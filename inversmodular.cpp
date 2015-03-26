#include <fstream>
#include <vector>

using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");

struct EuclidResult {
	int x,y,gcd;
};

EuclidResult euclid(int a, int b) {
	if(b==0) {
		return {1,0,a};
	}
	else {
		EuclidResult last = euclid(b,a%b);
		return {last.y,last.x-(a/b)*last.y,last.gcd};
	}
}

unsigned inv_mod(unsigned a, unsigned mod) {
	EuclidResult res = euclid(a,mod);
	while(res.x < 0) res.x+= mod;
	return res.x;
}

int main() {
	int a,n;
	in >> a >> n;
	out << inv_mod(a,n) << '\n';

	return 0;
}