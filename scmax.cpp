#include <fstream>
#include <vector>
using namespace std;

ifstream in ("scmax.in");
ofstream out ("scmax.out");

struct sol {
	unsigned p,l;
};

int n;
vector<unsigned long long> v;
vector<sol> dp;

int main() {
	in >> n;
	v.resize(n);
	dp.resize(n);
	for(int i = 0; i < n; ++i) {
		in >> v[i];
	}

	dp[n-1].p=n-1;
	dp[n-1].l=1;

	int mx = 0;
	int iS = -1;

	for(int i = n-1; i >= 0; --i) {
		dp[i].p=i;
		dp[i].l=1;
		for(int j = i+1; j < n; ++j) {
			if(v[i]<v[j] && dp[i].l <= dp[j].l) {
				dp[i].l=dp[j].l+1;
				if(dp[i].l > mx) {
					mx = dp[i].l;
					iS = i;
				}
				dp[i].p=j;
			}
		}
	}

	out << mx << '\n';
	for(int i = 0,j=iS; i < mx; ++i,j=dp[j].p) {
		out << v[j] << ' ';
	}

}
