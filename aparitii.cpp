#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
ifstream in("aparitii.in");
ofstream out("aparitii.out");

unsigned cifFr[10][10];

void ProcessNr(unsigned n) {
	size_t i = 0;
	while(n) {
		cifFr[i++][n%10]++;
		n/=10;
	}
}

unsigned MissingNumber(unsigned k) {
	unsigned number = 0;
	for(int i = 9; i >= 0; --i) {
		number*=10;
		for(unsigned c = 0; c < 10; ++c) {
			if(cifFr[i][c]%k!=0)
				number += c;
		}
	}
	return number;
}

int main() {
	unsigned n,k;
	in >> n >> k;

	for(size_t i = 0; i < n; ++i) {
		unsigned a;
		in >> a;
		ProcessNr(a);
	}

	out << MissingNumber(k);
}
