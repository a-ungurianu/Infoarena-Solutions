#include <fstream>
using namespace std;
ifstream in ("rucsac.in");
ofstream out ("rucsac.out");

short n,g;
int dp[10001], p[5001], w[5001];

inline int max(int a, int b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	in >> n >> g;
	for(short i = 1; i <= n; i++)
		in >> w[i] >> p[i];
	for(short i = 1; i <= n; i++)
		for(short j = g; j >= 0; j--)
		{
			if(j >=w[i])
				dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
			else
				dp[j]=dp[j];
		}
	out << dp[g];
}
