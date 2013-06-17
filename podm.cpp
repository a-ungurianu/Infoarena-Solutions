#include <fstream>
#define ULL unsigned long long
using namespace std;
ifstream in ("podm.in"); ofstream out ("podm.out");
int p[512];
ULL m[512][512];
 
ULL optMatProd(int n, int*p)
{
  for(int l = 2; l <= n; l++)
  {
    for(int i = 1; i <=n-l+1;i++)
    {
      int j = i+l-1;
      m[i][j]=0xffffffffffffffff;
      for(int k = i; k <= j-1; k++)
      {
        ULL q = m[i][k]+m[k+1][j]+(1LL*p[i-1]*p[k]*p[j]);
        if(q<m[i][j])m[i][j]=q;
      }
    }
  }
  return m[1][n];
}
 
int n;
int main()
{
  in >> n;
  for(int i = 0; i <= n; i++)
  {
    in >> p[i];
  }
  ULL res = optMatProd(n,p);
  out << res << '\n';
 
}
