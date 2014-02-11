#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in("damesah.in");
ofstream out("damesah.out");

typedef vector<int> vec_i;
typedef vector<bool> vec_b;

int sol[14];
bool colOcup[28],mainDiagOcup[28],secDiagOcup[28];
size_t n,solCount;

bool isSafe(int i, int j) {
	return !(colOcup[j]||mainDiagOcup[n+j-i]||secDiagOcup[i+j]);
}

void printSol() {
	for(size_t i = 0; i < n; ++i)
		out << sol[i]+1 << ' ';
	out << '\n';
}

void solve(size_t i) {
	if(i==n) { 
		if(solCount == 0)
			printSol();
		solCount++;
		return;
	}
	for(size_t j = 0; j < n; ++j) {
		if(isSafe(i,j)) {
			sol[i] = j;
			colOcup[j] = mainDiagOcup[n+j-i] = secDiagOcup[i+j] = true;
			solve(i+1);
			colOcup[j] = mainDiagOcup[n+j-i] = secDiagOcup[i+j] = false;
		}
	}
}

int main() {
	in >> n;
	solve(0);
	out << solCount << '\n';
}
