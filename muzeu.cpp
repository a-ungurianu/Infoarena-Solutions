#include <fstream>
#include <queue>
#include <cstring>
#include <vector>
 
using namespace std;
 
ifstream in ("muzeu.in");
ofstream out ("muzeu.out");
 
int n;
 
struct dot
{
    int x;
    int y;
};
 
dot make_dot(int x,int y)
{
    dot newDot;
    newDot.x = x;
    newDot.y = y;
    return newDot;
}
 
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
int main()
{
    in >> n;
    int** ar = new int*[n+2];
    for( int i = 0; i < n+2; i++ )
    {
        ar[i] = new int[n+2];
        memset(ar[i],0,(n+2)*sizeof(int));
    }
 
    for( int i = 0; i < n+2; i++ )
    {
        ar[i][0]=ar[0][i]=ar[n+1][i]=ar[i][n+1]=-2;
    }
 
    vector<dot> paz;
 
 
    for( int i = 1; i <= n; i++ )
    {
        in.ignore();
        for( int j = 1; j <= n; j++ )
        {
            switch(in.get())
            {
                case '#':ar[i][j]=-2;break;
                case 'P':paz.push_back(make_dot(i,j));break;
            }
        }
    }
 
    queue<dot> q;
 
    int nrPaz = paz.size();
 
    for( int i = 0; i < nrPaz; i++ )
    {
        q.push(paz[i]);
        int x = paz[i].x;
        int y = paz[i].y;
        ar[x][y] = -3;
    }
 
    for( ;!q.empty();q.pop() )
    {
        dot curDot = q.front();
        int x;
        int y;
        for( int k = 0; k < 4; k++ )
        {
            x = curDot.x+dx[k];
            y = curDot.y+dy[k];
            if( ar[x][y]==0 )
            {
                q.push(make_dot(x,y));
                if(ar[curDot.x][curDot.y]==-3)
                    ar[x][y] = 1;
                else
                    ar[x][y] = ar[curDot.x][curDot.y] + 1;
            }
        }
    }
 
    for( int i = 1; i <=n; i++ )
    {
        for( int j = 1; j<=n;j++ )
        {
            if(ar[i][j] == -3)
            {
                out << 0 << ' ';
                continue;
            }
            if( ar[i][j] == 0 )
            {
                out << -1<< ' ';
                continue;
            }
            out <<ar[i][j]<< ' ';
        }
        out << '\n';
    }
}
