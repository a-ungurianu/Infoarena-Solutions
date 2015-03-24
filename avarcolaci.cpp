#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream in("avarcolaci.in");
	size_t no_tests;
	in >> no_tests;
	vector<int> candidate(no_tests,-1);
	for(size_t t = 0; t < no_tests; ++t) {
		size_t n;
		in >> n;
		unsigned k = 0;
		for(size_t i = 0; i < 2*n; ++i) {
			unsigned val;
			in >> val;

			if(k==0) {
				candidate[t] = val;
				k=1;
			}
			else if(candidate[t] == val) {
				k++;
			}
			else {
				k--;
			}
		}
	}

	in.close();
	in.open("avarcolaci.in");

	ofstream out("avarcolaci.out");

	in >> no_tests;
	for(size_t t = 0; t < no_tests; ++t) {
		size_t n;
		in >> n;
		unsigned count = 0;
		for(size_t i = 0; i < 2*n; ++i) {
			unsigned val;
			in >> val;
			if(val == candidate[t]) {
				count++;
			}
		}
		if(count > n) {
			out << candidate[t] << '\n';
		}
		else {
			out << "Mozart" << '\n';
		}
	}

	return 0;
}