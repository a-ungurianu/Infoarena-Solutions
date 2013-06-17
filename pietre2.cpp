#include <fstream>
#include <queue>
using namespace std;
ifstream in ("pietre2.in"); ofstream out ("pietre2.out");
 
struct dot
{
    int xp;
    int yp;
    int x;
    int y;
    int l;
};
 
int n,pir[102][102],dx[]={0,1,0,-1},dy[]={1,0,-1,0};
 
dot make_dot(int xp,int yp,int x, int y, int l)
{
    dot c;
    c.x = x;
    c.y = y;
    c.l = l;
    c.xp = xp;
    c.yp = yp;
    return c;
}
 
int main()
{
    in >> n;
    for( int i = 0; i <=n+1; i++ )pir[0][i]=pir[i][0]=pir[i][n+1]=pir[n+1][i]=-1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            in >> pir[i][j];
        }
    }
    queue<dot> q;
    for( int i = 1; i <=n; i++ )
    {
        q.push(make_dot(i,1,i,1,0));
        q.push(make_dot(1,i,1,i,0));
        q.push(make_dot(i,n,i,n,0));
        q.push(make_dot(n,i,n,i,0));
    }
    int maxL = 0;
    int mxp = 0;
    int myp = 0;
    for( ;!q.empty();q.pop() )
    {
        dot c = q.front();
        int x;
        int y;
        bool isEnd = true;
        for( int k = 0; k<4; k++ )
        {
            x=c.x+dx[k];
            y=c.y+dy[k];
            if(pir[x][y] == pir[c.x][c.y] + 1)
            {
                q.push(make_dot(c.xp,c.yp,x,y,c.l+1));
                isEnd = false;
            }
        }
        if(isEnd)
        {
            if(maxL<c.l)
            {
                maxL=c.l;
                mxp = c.xp;
                myp = c.yp;
            }
        }
    }
    out << maxL <<'\n';
    out << mxp << ' ' << myp;
 
 
}
