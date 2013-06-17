#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("linterv.in"); ofstream out("linterv.out");
 
struct inter
{
    int st;
    int fn;
};
 
int t;
inter ins[5002];
 
bool comp(inter a, inter b)
{
    return a.st < b.st;
}
 
int lenInt(int n)
{
    for(int i = 0; i < n; i++)
    {
        in >> ins[i].st >> ins[i].fn;
    }
    sort(ins,ins+n,comp);
    int start,finish;
    start = ins[0].st;
    finish = ins[0].fn;
    int sum = 0;
    bool ok = true;
    for(int i = 1; i < n; i++)
    {
        if(ins[i].st>=start&&ins[i].fn<=finish)continue;
        if(ins[i].st>=start&&ins[i].st<=finish)finish = ins[i].fn;
        if(ins[i].st>=finish){ok = false;sum+=finish-start;start = ins[i].st;finish = ins[i].fn;}
    }
    if(ok)return finish-start;
    return sum;
}
 
int main()
{
    in >> t;
    int n;
    while(t--)
    {
        in >> n;
        out << lenInt(n) << '\n';
    }
}
