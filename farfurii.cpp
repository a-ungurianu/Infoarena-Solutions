#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long BigUnsigned;

vector<unsigned> gen_perm(unsigned n, BigUnsigned k) {
	BigUnsigned m = ceil((1+sqrt(1.0f+8.0f*k))/2.0f);

	vector<unsigned> result;

	for(int i = 1; i <= n-m; ++i) {
		result.push_back(i);
	}
	unsigned swap_val = n-(m*(m-1)/2-k);
	result.push_back(swap_val);
	for(int i = n; i > n-m; --i) {
		if(i!=swap_val)
			result.push_back(i);
	}

	return result;
}

int main() {

	ifstream in("farfurii.in");
	unsigned n;
	BigUnsigned k;
	in >> n >> k;

	vector<unsigned> perm = gen_perm(n,k);

	ofstream out("farfurii.out");
	for(unsigned i:perm) {
		out << i << ' ';
	}
}