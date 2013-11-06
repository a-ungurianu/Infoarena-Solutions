#include <fstream>
#include <stack>
using namespace std;

ifstream in ("stergeri.in");
ofstream out ("stergeri.out");

struct ins {
    int p,k;
};

stack<ins> insers;

int main()
{
    int n,m,k;
    in >> n >> m >> k;

    for(int i = 0; i < m; ++i) {
         int a,b;
         in >> a >> b;
         insers.push((ins){a,b-a+1});
    }

    while(!insers.empty()) {
        ins t = insers.top();
        insers.pop();
        if(t.p<=k)k+=t.k;
    }
    out << k;
}
