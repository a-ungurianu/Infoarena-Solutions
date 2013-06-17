#include <fstream>
#include <map>
#include <string>
using namespace std;
ifstream in ("reteta2.in"); ofstream out ("reteta2.out");
 
int main()
{
  int totalTime=0;
  map<string,int> rt;
  while(in.peek()!='\n')
  {
    if(in.peek()=='('||in.peek()==' '){in.ignore();continue;};
    if('a'<=in.peek()&&in.peek()<='z')
    {
      string t;
      in >> t;
      int ct;
      in >> ct;
      rt[t]+=ct;
      continue;
    }
    if(in.peek()==')')
    {
      in.ignore();
      int t;
      in >> t;
      totalTime+=t;
    }
  }
  out << totalTime << '\n';
  for(map<string,int>::iterator it = rt.begin(); it!=rt.end(); it++)
    out << it->first << ' ' << it->second << '\n';
}
