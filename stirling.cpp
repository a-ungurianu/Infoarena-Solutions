#include <fstream>
#define M 98999
using namespace std;
ifstream in ("stirling.in"); ofstream out ("stirling.out");
 
long long memoS1[202][202];
long long memoS2[202][202];
 
int main()
{
  memoS1[0][0]=1;
  for(int i = 1; i <= 200; i++)
    for(int j = 1; j <=200; j++)
      memoS1[i][j]=(memoS1[i-1][j-1]-(i-1)*memoS1[i-1][j])%M;
  for(int i = 0; i <= 200; i++)
  {
    memoS2[i][1]=memoS2[i][i]=1;
  }
  for(int i = 2; i <= 200; i++)
    for(int j = 2 ; j <= 200; j++)
      memoS2[i][j]=(memoS2[i-1][j-1]+j*memoS2[i-1][j])%M;
  int t;
  in >> t;
  for(int i = 0; i < t; i++)
  {
    int kind;
    int n,m;
    in >> kind >> n >> m;
    if(kind == 1)out << memoS1[n][m] << '\n';
    else out << memoS2[n][m] << '\n';
  }
 
}
