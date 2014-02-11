#include <iostream>
#include <fstream>

using namespace std;
ifstream in("paranteze.in");
ofstream out("paranteze.out");

char sol[25];

void PrintSol(size_t n) {
	out << sol << '\n';
}

void back(int openStock, int closeStock, size_t lvl, size_t n) {
	while(closeStock >= 0) {
		if(openStock > 0) {
			sol[lvl] = '(';
			back(openStock-1,closeStock+1,lvl+1,n);
		}
		if(closeStock-- > 0) {
			sol[lvl++] = ')';
			if(lvl == n)
				PrintSol(n); 
		}
	}
}

int main() {
	size_t n;
	in >> n;
	back(n,0,0,2*n);
	return 0;
}
