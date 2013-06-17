#include <fstream>
#include <cstring>

std::ifstream in ("ciur.in"); 
std::ofstream out ("ciur.out");

int n;

int main()
{
  in >> n;
  bool* ciur = new bool[n];
  memset(ciur,0,n);
 
  for(int i = 2; i < n/2; i++)
  {
    if(!ciur[i])
    {
      for(int j = i+i; j < n; j+=i)
      {
        ciur[j]=true;
      }
    }
  }

  int nrDiv=0;
  for(int i = 2; i < n; i++)
  {
    if(!ciur[i])nrDiv++;
  }

  out << nrDiv;
}
