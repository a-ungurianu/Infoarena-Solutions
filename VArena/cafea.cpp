#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
ifstream in("cafea.in");
ofstream out("cafea.out");

struct Seller {
	unsigned cost;
	unsigned cant;
	bool operator< (const Seller &a) const {
		return float(cant)/cost > float(a.cant)/a.cost;
	}
};



int main() {
	vector<Seller> sellers;
	long long k, s, n;
	
	in >> k >> s >> n;
	
	sellers.resize(n);
	for(size_t i = 0; i < n; ++i)
		in >> sellers[i].cant >> sellers[i].cost;
	
	sort(sellers.begin(), sellers.end());
	long long curSum = 0;

	for(size_t i = 0; i < n && k; ++i) {
		//cerr << sellers[i].cant << ' ' << sellers[i].cost << '\n';
		if(k >= sellers[i].cant) {
			curSum+=sellers[i].cost;
			k-=sellers[i].cant;
		}
		else {
			curSum += ceil((float(k)/sellers[i].cant)*float(sellers[i].cost));
			k = 0;
			break;
		}
	}
	cerr << k <<'\n';
	if(k == 0 && s-curSum > 0) 
		out << s-curSum;
	else
		out << 0;

	return 0;
}
