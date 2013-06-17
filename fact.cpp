#include <fstream>
#define BIGN 2000000000
using namespace std;
ifstream in ("fact.in");
ofstream out ("fact.out");
int p,v[15];
int main()
{
    in >> p;
    v[0] = 1;
 
    int d = 0;
    for(int i = 5; i <= p*5; i = i*5) v[++d]=i;
    v[++d]=BIGN;
 
    int k = 1, u = p*5,m,s;
    while(k <= u)
    {
        m = (k + u)/2;
        s = 0;
        for (int j = 1; v[j] <= m; j++) s = s + m/v[j];
        if (s>=p) u = m - 1;
        else k = m + 1;
    }
    s = 0;
    for (int j = 1; v[j] <= k;j++) s = s + k/v[j];
 
    if (s == p) out << k << "\n";
    else
    {
        if (p==0) out<<v[0];
        else out<<-1<<"\n";
    }
    return 0;
}
