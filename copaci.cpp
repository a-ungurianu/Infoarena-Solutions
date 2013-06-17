#include <fstream>
#include <algorithm>
typedef long long ll;
typedef unsigned ll ull;

std::ifstream in ("copaci.in");
std::ofstream out ("copaci.out");
 
struct point
{
  ll x,y;
};

ull cmmdc(ull a,ull b);
 
int n;
point pts[100005];
int main()
{
  in >> n;
  for(int i = 0; i < n; i++)
  {
    ll x,y;
    in >> x >> y;
    pts[i]=(point){x,y};
  }
  pts[n]=pts[0];
  ll A=0;
  ull B=0;
  for(int i = 0; i < n; i++)
  {
    A+=(pts[i].x*pts[i+1].y-pts[i+1].x*pts[i].y);
    B+=cmmdc(abs(pts[i].x-pts[i+1].x),abs(pts[i].y-pts[i+1].y));
  }
  A = abs(A);
  out << (A-B+2)/2;
}
 
ull cmmdc(ull a, ull b)
{
  if(a==0)return b;
  if(b==0)return a;
  return cmmdc(b,a%b);
}
