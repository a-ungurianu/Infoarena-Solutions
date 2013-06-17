#include <fstream>
using namespace std;
ifstream in ("euclid2.in"); ofstream out ("euclid2.out");
 
int gcd(int a, int b)
{
  int r = a%b;
  while(r)
  {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}
 
int t,a,b;
 
int main()
{
  in >> t;
  while(t--)
  {
    in >> a >> b;
    out << gcd(a,b) << '\n';
  }
}
