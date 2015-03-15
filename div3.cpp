#include <fstream>

using namespace std;

unsigned pd[2][3];
unsigned r3[3];

int main() {

	ifstream in("div3.in");
	unsigned n,k;
	in >> n >> k;
	for(int i = 0; i < n; ++i) {
		unsigned val;
		in >> val;
		r3[val%3]++;
	}
	for(int i = 0; i < 3; ++i) {
		pd[0][i] = r3[i];
	}

	for(int i = 1; i < k; ++i) {
		pd[1][0] += r3[0]*pd[0][0]; 
		pd[1][0] += r3[1]*pd[0][2];
		pd[1][0] += r3[2]*pd[0][1];
		
		pd[1][1] += r3[0]*pd[0][1]; 
		pd[1][1] += r3[1]*pd[0][0];
		pd[1][1] += r3[2]*pd[0][2];
		
		pd[1][2] += r3[0]*pd[0][2]; 
		pd[1][2] += r3[1]*pd[0][1];
		pd[1][2] += r3[2]*pd[0][0];
		
		for(int j = 0; j < 3; ++j) {
			pd[0][j] = pd[1][j] % 4001;
			pd[1][j] = 0;
		}
	}

	ofstream out("div3.out");
	out << pd[0][0] % 4001 << '\n';
}