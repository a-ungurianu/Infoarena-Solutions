#include <fstream>
#include <queue>
using namespace std;
ifstream in ("tsunami.in"); ofstream out ("tsunami.out");
 
int n,m,h;
short sea[1002][1002];
short dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
 
struct dot
{
    int x;
    int y;
};
 
dot make_dot(int x,int y)
{
    dot cur;
    cur.x = x;
    cur.y = y;
    return cur;
}
 
bool HasNbh( int i, int j )
{
    for( int k = 0; k<4;k++ )if(sea[i+dx[k]][j+dy[k]]!=0)return true;
    return false;
}
 
int main()
{
    in >> n >> m >> h;
    queue<dot> q;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            in >> sea[i][j];
        }
    }
 
    for( int i = 0; i <=m+1;i++ )sea[0][i]=sea[n+1][i]=-1;
    for( int i = 0; i <=n+1;i++ )sea[i][0]=sea[i][m+1]=-1;
 
 
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++)
        {
            if( sea[i][j] == 0 && HasNbh(i,j) )sea[i][j]=-1,q.push(make_dot(i,j));
        }
    }
    int cnt = 0;
    for( ;!q.empty();q.pop() )
    {
        dot c = q.front();
        for( int k = 0; k<4;k++ )
        {
            if( sea[c.x+dx[k]][c.y+dy[k]] < h && sea[c.x+dx[k]][c.y+dy[k]] != -1 )
            {
                if(sea[c.x+dx[k]][c.y+dy[k]]!=0)cnt++;
                q.push(make_dot(c.x+dx[k],c.y+dy[k]));
                sea[c.x+dx[k]][c.y+dy[k]] = -1;
            }
        }
    }
 
    out << cnt;
 
}
