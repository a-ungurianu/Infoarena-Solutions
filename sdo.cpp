#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in ("sdo.in"); ofstream out ("sdo.out");
int main()
{
  vector<unsigned int> v;
  int n;
  in >> n;
 
  int k;
  in >> k;
  for(int i = 0; i < n;i++)
  {
    unsigned int t;
    in >> t;
    v.push_back(t);
  }
  nth_element(v.begin(),v.begin()+k-1,v.end());
  out << v[k-1];
}
