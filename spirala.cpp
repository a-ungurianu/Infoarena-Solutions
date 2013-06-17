#include <fstream>
#include <vector>
using namespace std;
ifstream in ("spirala.in"); ofstream out ("spirala.out");
vector<int> vc;
int mat[102][102];
void unRoll(int sX,int sY, int fX, int fY);
 
int main()
{
  int n,m;
  in >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0;j < m; j++)
      in >> mat[i][j];
  unRoll(0,0,m,n);
  int r = vc[1]-vc[0];
  for(int i = 2; i < vc.size();i++)
  {
    if(vc[i]-vc[i-1]!=r)
    {
      out << "NU\n";
      out << vc[i-1] << ' ' << vc[i];
      return 0;
    }
  }
  out << "DA\n";
  out << vc.back();
}
void unRoll(int sX,int sY, int fX, int fY)
{
  if(fX==sX)return;
  if(fY==sY)return;
  if(fX-sX==1)
  {
    for(int y = sY;y<fY;y++)
      vc.push_back(mat[y][sX]);
    return;
  }
  if(fY-sY==1)
  {
    for(int x = sX; x < fX; x++)
      vc.push_back(mat[sY][x]);
    return;
  }
  for(int x = sX; x < fX; x++)
    vc.push_back(mat[sY][x]);
  for(int y = sY+1; y < fY; y++)
    vc.push_back(mat[y][fX-1]);
  for(int x = fX-2; x >= sX; x--)
    vc.push_back(mat[fY-1][x]);
  for(int y = fY-2;y > sY; y--)
    vc.push_back(mat[y][sX]);
  unRoll(sX+1,sY+1,fX-1,fY-1);
}
