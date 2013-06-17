#include <fstream>
#include <vector>
using namespace std;
ifstream in ("sume.in"); ofstream out ("sume.out");
 
int PtoN[25001];
int sums[255][255];
vector<int> res;
 
int main()
{
  int p;
  in >> p;
  int j=0;
  for(int i = 1; j <=p; i++)
  {
    j+=i;
    PtoN[j]=i+1;
  }
  PtoN[0]=PtoN[1]=PtoN[2]=0;
  int n = PtoN[p];
  if(n==0)
  {
    out << -1 << '\n';
    return 0;
  }
  unsigned long long sumin=0;
  for(int i = 1; i < n;i++)
    for(int j = i+1; j <=n;j++)
    {
      in >> sums[i][j];
      sumin+=sums[i][j];
    }
    unsigned long long sumout=0;
  int nr2 = sums[1][2]+sums[1][3]-sums[2][3];
  if(nr2%2==0&&nr2>0)
  {
    res.push_back(nr2/2);
    sumout+=nr2/2;
  }
  else { out << -1 << '\n';return 0;}
  nr2 = sums[1][2]+sums[2][3]-sums[1][3];
  if(nr2%2==0&&nr2>0)
  {
    res.push_back(nr2/2);
    sumout+=nr2/2;
  }
  else {out << -1<< '\n'; return 0;}
  for(int i = 3; i <= n; i++)
  {
    nr2 = sums[1][i]+sums[2][i]-sums[1][2];
    if(nr2%2==0&&nr2>0)
      {
        res.push_back(nr2/2);
        sumout+=nr2/2;
      }
    else { out << -1<< '\n'; return 0;}
  }
  if(sumin%sumout!=0)
  {
    out << -1;
    return 0;
  }
  out << n << '\n';
  for(int i = 0; i < res.size(); i++)
  {
    out << res[i] << ' ';
  }
  return 0;
}
