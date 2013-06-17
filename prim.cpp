#include <fstream>
#include <vector>
#define ULL unsigned long long
using namespace std;
ifstream in ("prim.in"); ofstream out ("prim.out");
 
bool ciur[3000000];
int k;
int last;
int nPrimes = 0;
void compPrimes();
int main()
{
  in >> k;
  compPrimes();
  out << 1LL*last*last;
}
 
void compPrimes()
{
  for(int d = 2; nPrimes<=k; d++)
  {
    if(!ciur[d])
    {
      last = d;
      nPrimes++;
      for(ULL i = d+d; i < 3000000; i+=d)
          ciur[i]=true;
    }
  }
}
