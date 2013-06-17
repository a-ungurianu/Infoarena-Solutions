#include <fstream>
#include <cstring>
using namespace std;
ifstream in ("sr.in"); ofstream out ("sr.out");
 
char a[100002],b[100002];
 
bool which[100002];
int main()
{
    in >> a >> b;
    int n = strlen(a);
    int m = strlen(b);
 
    int j = 0;
    bool ok = true;
    for( int i = 0; i <=n&&ok; i++ )
    {
        if( a[i] == b[j] )
        {
            which[i]=true;j++;
            if(j>=m)ok = false;
        }
    }
    for( int i = 0; i <= n; i++)
    {
        if(which[i])out << i+1 << ' ';
    }
}
