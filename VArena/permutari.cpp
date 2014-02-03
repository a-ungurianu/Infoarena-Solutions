#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("permutari.in");
ofstream out("permutari.out");

int main() {
	size_t n,k;
	in >> n >> k;
	
	vector<unsigned> v;
	for(size_t i = 0; i < n; ++i)
		v.push_back(i+1);

	unsigned permI = 1;
	for(size_t i = 0;i < k; ++i) {
		unsigned nextP;
		in >> nextP;
		while(permI != nextP) {
			next_permutation(v.begin(), v.end());
			permI++;
		}
		for(vector<unsigned>::iterator it = v.begin(); it!=v.end(); it++) {
			out << *it << ' ';
		}		
		out << '\n';
	}
	return 0;
}
