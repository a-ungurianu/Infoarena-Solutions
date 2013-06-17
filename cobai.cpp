#include <fstream>
#include <queue>

std::ifstream in ("cobai.in"); 
std::ofstream out ("cobai.out");

struct cel
{
  int ln;
  int col;
};
 
struct trU
{
  cel cl;
  int trI;
};

const short dc[]={0 ,1, 0,-1};
const short dl[]={-1,0, 1, 0};

int n,m;
int map[54][54];
short trs[1003];
 
void bord();
void printMap();
 
int main()
{
  in >> n >> m;

  bord();
  
  cel st;
  int nrP=0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
      char t;
      in >> t;
      switch(t)
      {
        case '*': st=(cel){i,j}; map[i][j]=-1; break;
        case '+': map[i][j]=-1; break;
        case '.': nrP++; break;
      }
    }
  int trSz=0;
  in.ignore();
  while(in.peek()!='\n')
  {
    char t;
    in >> t;
    switch(t)
    {
      case 'N': trs[trSz++] = 0; break;
      case 'E': trs[trSz++] = 1; break;
      case 'S': trs[trSz++] = 2; break;
      case 'V': trs[trSz++] = 3; break;
    }
  }
  if(trSz == 0)
  {
    out.precision(3);
    out.setf(std::ios::fixed);
    out << 0.00;
    return 0;
  }
  std::queue<trU> q;
  q.push( (trU){st,0} );
  double nrPb=0;
  for( ;!q.empty(); q.pop())
  {
    trU cr = q.front();
    int cC=cr.cl.col,lC=cr.cl.ln;
    cC+=dc[trs[cr.trI]];
    lC+=dl[trs[cr.trI]];
    if(cr.trI==trSz-1)
    {
      while(map[lC][cC]!=-1)
      {
        if(map[lC][cC]!=-2)
        {
          nrPb++;
          map[lC][cC]=-2;
        }
        cC+=dc[trs[cr.trI]];
        lC+=dl[trs[cr.trI]];
      }
    }
    else
    {
      while(map[lC][cC]!=-1)
      {
        if(cr.trI+1>map[lC][cC])
        {
          q.push((trU){(cel){lC,cC},cr.trI+1});
          map[lC][cC]=cr.trI+1;
        }
          cC+=dc[trs[cr.trI]];
          lC+=dl[trs[cr.trI]];
      }
    }
  }
  out.precision(5);
  out.setf(std::ios::fixed);
  out << nrPb/nrP*100 << '\n';
  printMap();
}
 
void bord()
{
  for(int i = 0; i <= n+1; i++)
    map[i][0]=map[i][m+1]=-1;
  for(int i = 0; i <=m+1; i++)
    map[0][i]=map[n+1][i]=-1;
}
void printMap()
{
  for(int i = 0; i <=n+1; i++)
  {
    for(int j = 0; j<=m+1;j++)
    {
      out.width(2);
      out << map[i][j] << ' ';
    }
    out << '\n';
  }
}
