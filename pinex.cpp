#include <fstream>
#include <vector>
#define ULL unsigned long long
#define cSz 1000000
using namespace std;
ifstream in ("pinex.in"); ofstream out ("pinex.out");
bool ciur[cSz];
vector<ULL> prims;
 
void makeCiur();
void addMul(int i,int dpth, int k, int n,vector<int> divs);
ULL solve(ULL a, ULL b);
ULL inex(ULL a, vector<int> div);
int nrReq;
ULL a,b;
ULL suma;
int main()
{
  makeCiur();
  in >> nrReq;
  while(nrReq--)
  {
    in >> a >> b;
    suma = 0LL;
    out << solve(a,b) << '\n';
  }
}
 
void makeCiur()
{
  for(int i = 2; i < cSz; i++)
    if(!ciur[i]){prims.push_back(i);for(int j = i+i; j <cSz;j+=i)ciur[j]=true;}
}
 
ULL curSum=0;
ULL solve(ULL a, ULL b)
{
  vector<int> bDiv;
  ULL aux = b;
  int i = 0;
  while(aux!=1&&i<prims.size())
  {
      if(aux%prims[i]==0)bDiv.push_back(prims[i]);
      while(aux%prims[i]==0)aux/=prims[i];
    i++;
  }
  if(aux!=1)bDiv.push_back(aux);
  return inex(a,bDiv);
}
ULL inex(ULL a, vector<int> divs)
{
  int sn = 1;
  int nrDivs = divs.size();
  for(int i = 1; i <= nrDivs; i++)
  {
    curSum=0LL;
    addMul(0,0,i,nrDivs,divs);
    suma+=sn*curSum*1LL;
    sn=(-sn);
  }
  return a-suma;
}
int v[1000003];
void addMul(int i,int dpth, int k, int n,vector<int> divs)
{
  if(dpth==k-1)
  {
    for(int j = i+1; j <= n; j++)
    {
      v[dpth]=j;
      ULL fact = 1;
      for(int l = 0; l < k;l++)fact*=divs[v[l]-1];
      curSum+=a/fact;
    }
  }
  else
  {
    for(int j = i+1; j <=n;j++)
    {
      v[dpth]=j;
      addMul(j,dpth+1,k,n,divs);
    }
  }
}
