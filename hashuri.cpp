#include <fstream>
#include <list>
#include <algorithm>
using namespace std;
ifstream in ("hashuri.in"); ofstream out ("hashuri.out");
static const int m = 666013;
list<int> hash[m];
 
int main()
{
  int n,t,val;
  in >> n;
  for(int i = 0; i < n; i++)
  {
    in >> t >> val;
    list<int>::iterator p;
    switch(t)
    {
      case 1: if(find(hash[val%m].begin(),hash[val%m].end(),val)==hash[val%m].end())hash[val%m].push_back(val);break;
      case 2: p = find(hash[val%m].begin(),hash[val%m].end(),val);if(p!=hash[val%m].end())hash[val%m].erase(p);break;
      case 3: if(find(hash[val%m].begin(),hash[val%m].end(),val)==hash[val%m].end()){out << "0\n"; break;}out <<"1\n";break;
    }
  }
}
