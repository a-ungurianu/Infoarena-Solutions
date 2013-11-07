#include <iostream>
#include <fstream>

using namespace std;
ifstream in ("densitate.in");
ofstream out ("densitate.out");

int sums[500001];
bool ciur[500001];

void createSieve(int n) {
	ciur[0]=1;
	ciur[1]=1;
	for(int i = 2; i < n/2; ++i) {
		if(!ciur[i])
			for(int j = i+i; j <= n; j+=i)
				ciur[j]=true;
	}
}

int main() {
	int n;
	in >> n;
	createSieve(n);
	for(int i = 2; i <= n; ++i) {
		if(!ciur[i])
			sums[i]=sums[i-1]+1;
		else
			sums[i]=sums[i-1];
	}

	int q;
	in >> q;
	for(int i = 0; i < q; ++i) {
		int a,b;
		in >> a >> b;
		out << sums[b] - sums[a-1] << '\n';
	}
}
