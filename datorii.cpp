#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("datorii.in");
ofstream out ("datorii.out");

int v[15001],bit[15001],n;

int RightmostOne(int x) {
	return x&(-x);
}

void BIT_Gen() {
	for(int i = 1; i <= n; ++i) {
		for(int j = i - RightmostOne(i) + 1; j <= i; j++) {
			//cerr << i;
			bit[i]+=v[j];
		}
	}
}

void BIT_Add(int idx, int val) {
	for(int i = idx; i <= n; i+=RightmostOne(i)) {
		//cerr << i;
		bit[i]+=val;
	}
}

int BIT_Compute(int idx) {
	int res = 0;
	for(int i = idx; i > 0; i-=RightmostOne(i)) {
		res+=bit[i];
	}
	return res;
}


int main() {
	int m;
	in >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		in >> v[i];
	}
	BIT_Gen();
	for(int i = 0; i < m; ++i) {
		int c;
		in >> c;
		switch(c) {
			case 0:
				int i,val;
				in >> i >> val;
				BIT_Add(i,-val);
				break;
			case 1:
				int st,fn;
				in >> st >> fn;
				out << BIT_Compute(fn)-BIT_Compute(st-1) << '\n';
				break;
		}
	}
	return 0;
}
