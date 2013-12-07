#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;
ifstream in ("cai.in");
ofstream out ("cai.out");

int n;

short match(unsigned cG, unsigned cI) {
	if(cG>cI)return 1;
	else if(cG==cI)return 0;
	return -1;
}




int main() {
	unsigned t;
	in >> t;
	while(t--) {
		in >> n;
		vector<unsigned> ionelHs,gigelHs;
		ionelHs.resize(n,0);
		gigelHs.resize(n,0);
		vector<vector<int>> pd;
		pd.resize(n);
		for(auto &l:pd) l.resize(n,0);
		for(int i = 0; i < n; ++i)
			in >> gigelHs[i];
		for(int i = 0; i < n; ++i)
			in >> ionelHs[i];	
		sort(gigelHs.begin(), gigelHs.end(),greater<unsigned>());
		sort(ionelHs.begin(), ionelHs.end(),greater<unsigned>());

		for(int i = 0; i < n; ++i) {
			pd[i][i]=match(gigelHs[i],ionelHs[n-1]);
		}

		//cerr << n << '\n';
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j < n-i; ++j) {
				int ind1 = j,ind2=i+j;
				//cerr << ind1+1 << ' ' << ind2 << '\n';
				//cerr << pd[ind1+1][ind2] << "\n\n";
				pd[ind1][ind2]=max(pd[ind1+1][ind2]+match(gigelHs[ind1],ionelHs[ind1+n-ind2-1]),
								   pd[ind1][ind2-1]+match(gigelHs[ind2],ionelHs[ind1+n-ind2-1]));
			}
		}
		out << pd[0][n-1]*200 <<'\n';
	}
}
