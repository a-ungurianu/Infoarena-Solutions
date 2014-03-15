#include <iostream>
#include <fstream>

using namespace std;
ifstream in("fructe.in");
ofstream out("fructe.out");

int main() {
	size_t t;
	in >> t;
	while(t--) {
		unsigned a,b;
		in >> a >> b;
		out << ((b%2==1)?1:0) << '\n';
	}
}
