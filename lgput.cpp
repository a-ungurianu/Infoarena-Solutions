#include <fstream>
#define M 1999999973
#define ULL unsigned long long
using namespace std;
ifstream in ("lgput.in"); ofstream out ("lgput.out");
 
ULL lgput(ULL a, ULL b)
{
    a = a%M;
    if(b==1)return a;
    if(b==0)return 1;
    if(b&1)
        return a*lgput(a*a,(b-1)/2)%M;
    return lgput(a*a,b/2)%M;
}
 
int main()
{
    unsigned int a,b;
    in >> a >> b;
    a%=M;
    ULL res = lgput(a,b)%M;
    out << res;
}
