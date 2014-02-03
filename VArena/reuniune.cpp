#include <iostream>
#include <fstream>

using namespace std;
ifstream in("reuniune.in");
ofstream out("reuniune.out");

int main() {
	int a1,a2,b1,b2;
	in >> a1 >> a2 >> b1 >> b2;
	if(a2 < b1 || b2 < a1) {
		out << -1 << '\n';
		return 0;
	}
	out << min(a1,b1) << ' ' << max(a2,b2) << '\n';
}
