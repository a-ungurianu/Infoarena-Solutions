#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("energii.in");
ofstream out("energii.out");

struct item {
	int price,energy;
};

const int oo = 1000000;

int n,neededEnergy,maxEnergy;
vector<item> rucsac;
vector<int> dp;

int main() {
	in >> n >> neededEnergy;
	rucsac.resize(n);
	for(int i = 0; i < n; ++i) {
		in >> rucsac[i].energy >> rucsac[i].price;
		maxEnergy=max(maxEnergy,rucsac[i].energy);
	}
	dp.resize(neededEnergy+maxEnergy+1);
	for(auto &i:dp)
		i=oo;
	dp[0]=0;
	int minCost = oo;

	for(int i = 0; i < n; ++i) {
		for(int j = neededEnergy; j >= 0; --j) {
			if(dp[j]!=oo && dp[j+rucsac[i].energy]>dp[j]+rucsac[i].price)
				dp[j+rucsac[i].energy]=dp[j]+rucsac[i].price;
		}
	}

	for(int i = neededEnergy; i <= neededEnergy+maxEnergy; ++i) {
		minCost = min(minCost,dp[i]);
	}

	if(minCost == oo)
		out << -1 << '\n';
	else
		out << minCost << '\n';

	return 0;
}
