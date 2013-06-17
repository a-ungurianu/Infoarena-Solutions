#include <cstdio>
#include <cstring>
using namespace std;
 
int cuvSz[2000000];
char buff[2000000];
 
int main()
{
  freopen("text.in","r",stdin);
  fread(buff,1,2000000,stdin);
  int n = strlen(buff);
  freopen("text.out","w",stdout);
  int nrL=0;
  int nrC=0;
  for(int i = 0; i < n; i++)
  {
    if(('A'<=buff[i]&&buff[i]<='Z')||('a'<=buff[i]&&buff[i]<='z')) nrL++;
    else if(i>0&&(('A'<=buff[i-1]&&buff[i-1]<='Z')||('a'<=buff[i-1]&&buff[i-1]<='z')))nrC++;
  }
  if(('A'<=buff[n-1]&&buff[n-1]<='Z')||('a'<=buff[n-1]&&buff[n-1]<='z')) nrC++;
  printf("%d\n",nrL/nrC);
}
