#include <iostream>
#include <fstream>

std::ifstream in ("bila.in");
std::ofstream out ("bila.out");

const short dl[] = {1,0,-1,0};
const short dc[] = {0,1,0,-1};

int n,m;
unsigned short map[127][127];
unsigned short dp[127][127];

unsigned short getTrLen(const unsigned short i, const unsigned short j)
{
	if(dp[i][j]!=0)return dp[i][j];
	unsigned short iM=i,jM=j;
	for(unsigned short k = 0; k < 4; k++)
	{
		int iN,jN;
		iN = i+dl[k];
		jN = j+dc[k];
		if(map[iN][jN]<map[iM][jM])
		{
			iM = iN;
			jM = jN;
		}
	}
	if(iM==i&&jM==j)
		return 0;
	dp[i][j] = 1+getTrLen(iM,jM);
	return dp[i][j];
}

int main()
{
	in >> n >> m;
	for (unsigned short i = 1; i <= n; ++i)
		for (unsigned short j = 1; j <= m; ++j)
			in >> map[i][j];
	
	for(unsigned short i = 0; i <= n; ++i)
		map[i][0]=map[i][m+1]=65001;
	for(unsigned short j = 0; j <= m; ++j)
		map[0][j]=map[n+1][j]=65001;

	unsigned short maxTrLen = 0, minTrHeight = 65001;
	for(unsigned short i = 1; i <= n; ++i)
		for(unsigned short j = 1; j <= m; ++j)
		{
			if(dp[i][j])continue;
			unsigned short ln = getTrLen(i,j);
			if(ln > maxTrLen)
			{
				maxTrLen = ln;
				minTrHeight = map[i][j];
			}
			else if (ln == maxTrLen && map[i][j]<minTrHeight)
				minTrHeight=map[i][j];
		}
	out << maxTrLen+1 << ' ' << minTrHeight << '\n';
}
