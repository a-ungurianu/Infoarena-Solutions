#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

ifstream in("strmatch.in");
ofstream out("strmatch.out");

const unsigned M1 = 100007;
const unsigned M2 = 100021;
const unsigned P = 101;
unsigned PN1=1,PN2=1;

char a[2000002],b[2000002];

int main() {
	in.get(a,2000001);
	in.ignore();
	in.get(b,2000001);

	unsigned la = strlen(a);
	unsigned lb = strlen(b);

	if(la > lb) {
		out << "0\n";
		return 0;
	}

	int small_hash1 = 0,small_hash2 = 0;
	int big_hash1 = 0, big_hash2 = 0;
	for(unsigned i = 0; i < la; ++i) {
		small_hash1 = (small_hash1 * P + a[i])%M1; 
		small_hash2 = (small_hash2 * P + a[i])%M2;

		big_hash1 = (big_hash1 * P + b[i])%M1; 
		big_hash2 = (big_hash2 * P + b[i])%M2;


		if(i!=0) {
			PN1 = (PN1*P)%M1;
			PN2 = (PN2*P)%M2;
		}
	}

	vector<unsigned> solutions;

	unsigned count = 0;
	if(small_hash1 == big_hash1 && small_hash2 == big_hash2) {
		solutions.push_back(0);
		count ++;
	}

	for(unsigned i = la; i < lb; ++i) {
		big_hash1 = ((big_hash1 - (PN1*b[i-la]) % M1 + M1)*P + b[i])%M1;
		big_hash2 = ((big_hash2 - (PN2*b[i-la]) % M2 + M2)*P + b[i])%M2;
		if(small_hash1 == big_hash1 && small_hash2 == big_hash2) {
			if(count < 1000)
				solutions.push_back(i-la+1);
			count ++;
		}
	}

	out << count << '\n';
	for(unsigned i = 0; i < solutions.size(); ++i) {
		out << solutions[i] << ' ';
	}

	out << '\n';

	return 0;
}