#include <fstream>
#include <algorithm>

using namespace std;
ifstream in ("cmlsc.in"); ofstream out ("cmlsc.out");

const int NMax=1024;
int m,n;

int A[NMax], B[NMax], dp[NMax][NMax], sol[NMax];

int main() 
{
	in >> m >> n;
	for(int i = 1; i <= m; i++)
		in >> A[i];
	for(int i = 1; i <= n; i++)
		in >> B[i];

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if (A[i] == B[j])
			{
				//daca cele 2 sunt egale, valoarea lor este egala cu cea a vecinului din stanga sus + 1
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				//daca nu, valoarea lor este minimul dintre valoarea de sus si cea din stanga
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
	int solLen = 0;
	for (int i = m, j = n; i; )
		if (A[i] == B[j])
		{
			//daca cele 2 sunt egale,se introduce in sir si se merge pe diagonala scundara in sus
			sol[++solLen] = A[i], --i, --j;
		}
		else if (dp[i-1][j] >= dp[i][j-1])
			--i;
		else
			--j;

		out << solLen << '\n';
		out << sol[solLen];
	for (int i = solLen-1; i; --i)// se scrie subsirul comun in ordine inversa
		out  << ' ' << sol[i];
	out << '\n';
	return 0;
}
