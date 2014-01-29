#include <fstream>
using namespace std;

ifstream in("adunare.in");
ofstream out("adunare.out");

int main() {
	int a,b;
	in >> a >> b;
	out << a+b << '\n';
	return 0;
}
