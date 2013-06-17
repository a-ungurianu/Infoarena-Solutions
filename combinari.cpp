#include <fstream>
 
std::ifstream in ("combinari.in"); 
std::ofstream out("combinari.out");
 
int n,k;
short sol[20];
 
void back(int l)
{
  if(l==k) {
    for(int i = 1; i <= k; i++)
      out << sol[i] << ' ';
    out << '\n';
  }
  else
    for(int i = sol[l]+1; i <= n; i++)
    {
      sol[l+1]=i;
      back(l+1);
    }
}
 
int main()
{
  in >> n >> k;
  back(0);
  return 0;
}
