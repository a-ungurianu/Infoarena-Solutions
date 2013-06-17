#include <fstream>
using namespace std;
ifstream in ("tabela.in"); ofstream out ("tabela.out");
unsigned int l,c;
 
int main()
{
  in >> l >> c;
  l--;c--;
  out << (l^c);
  return 0;
}
