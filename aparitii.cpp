#include <iostream>
#include <fstream>

using namespace std;

ifstream in("aparitii.in");
ofstream out("aparitii.out");

// digitFrec[digitPos][digit] show the number of times digit
// appears in position digitPos (counted form right to left)
unsigned digitFrec[10][10];

void ProcessNumber(unsigned number) {
	size_t digitPos = 0;
	while(number) {
		digitFrec[digitPos++][number % 10]++;
		number/=10;
	}
}

// This works because if we have a digit appear in a position
// a number of times which is not divisible by k, then that digit
// has that position in the missing number we are trying to find.
unsigned MissingNumber(unsigned k) {
	unsigned number = 0;
	for(int digitPos = 9; digitPos >= 0; --digitPos) {
		number *= 10;
		for(unsigned digit = 0; digit < 10; ++digit) {
			if(digitFrec[digitPos][digit] % k != 0)
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
