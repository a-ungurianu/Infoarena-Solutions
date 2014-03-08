#include <iostream>
#include <fstream>

using namespace std;
ifstream in("modulo.in");
ofstream out("modulo.out");

typedef unsigned long long Big;

Big PowMod(Big b, Big e, Big m) {
	if(e == 0) return 1;
	if(e == 1) return b%m;
	if(e%2) {
		unsigned h = PowMod(b%m,(e-1)/2,m);
		return (b*h*h)%m;
	}
	else {
		unsigned h = PowMod(b%m,e/2,m);
		return (h*h)%m;
	}
}

int main() {
	Big a,b,c;
	in >> a >> b >> c;
	out << PowMod(a,b,c);
}
