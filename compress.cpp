#include <fstream>

std::ifstream in ("compress.in");
std::ofstream out ("compress.out");
int main()
{
  char cur;
  in >> cur;
  int nr = 1;
  while(in.peek()!='\n')
  {
    char t;
    in >> t;
    if (t != cur)
    {
      out << cur << nr;
      nr = 1;
      cur = t;
    }
    else nr++;
  }
  out << cur << nr;
}
