#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

typedef unsigned long long big;

using namespace std;

ifstream in("shop.in");
ofstream out("shop.out");

struct coin {
	big val;
	int ind;
	int nr;
	bool operator< (const coin& a) const {
		return val > a.val;
	}
};

big pow(int base,int e) {
	if(e==0)return 1ull;
	return base*pow(base,e-1);
}

vector<coin> pocket;
vector<unsigned> coinsUsed;
int n,base;
big price;

int main() 
{
	in >> n >> base >> price;
	pocket.resize(n);
	coinsUsed.resize(n);
	for(int i = 0; i < n; ++i) {
		int e;
		in >> e;
		in >> pocket[i].nr;
		pocket[i].ind=i;
		pocket[i].val = pow(base,e);
	}
	
	sort(pocket.begin(), pocket.end());
	
	int ind = 0;
	int totalCoins = 0;

	while(price>0 && ind < n) {
		if(pocket[ind].nr==0 || pocket[ind].val>price){
			ind++;
			continue;
		}
		price-=pocket[ind].val;
		pocket[ind].nr--;
		coinsUsed[pocket[ind].ind]++;
		totalCoins++;
	}
	out << totalCoins << '\n';
	for(int i = 0; i < n; ++i) {
		out << coinsUsed[i] << ' ';
	}
	out << '\n';
	return 0;
}
