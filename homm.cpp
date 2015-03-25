#include <fstream>

using namespace std;

typedef unsigned long long BigUnsigned;
 
BigUnsigned map[102][102],dp[102][102][22];
 
const short dl[]={0,1,0,-1};
const short dc[]={1,0,-1,0};
 
int main()
{
    ifstream in("homm.in");
    ofstream out("homm.out");

    size_t n,m,k;
    in >> n >> m >> k;
    
    for(size_t i = 0; i <= n+1; i++)
        map[i][0]=map[i][m+1]=1;
    
    for(int i = 0; i <= m+1; i++)
        map[0][i]=map[n+1][i]=1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            in >> map[i][j];
    
    size_t stL,stC,fnL,fnC;
    in >> stL >> stC >> fnL >> fnC;
    
    if(map[fnL][fnC]!=0) {
        out << 0;
        return 0;
    }
    
    for(int d = 0; d < 4; d++)
        if(map[stL+dl[d]][stC+dc[d]]==0)
            dp[stL+dl[d]][stC+dc[d]][1]=1ULL;
    
    for(int cK = 2; cK <= k; cK++)
    {
        for(int l = 1; l <= n; l++)
        {
            for(int c = 1; c <= m; c++)
            {
                if(map[l][c]==0)
                {
                    for(int d = 0; d < 4; d++)
                        dp[l][c][cK]+=dp[l+dl[d]][c+dc[d]][cK-1];
                }
            }
        }
    }

    size_t res = 0;
    for(int i = 1; i <= k; i++)
        res+=dp[fnL][fnC][i];
    
    if(stL==fnL && stC==fnC)res++;
    out << res;
}