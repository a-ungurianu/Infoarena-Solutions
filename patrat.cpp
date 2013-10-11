#include <fstream>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

ifstream in ("patrat.in");
ofstream out ("patrat.out");

unsigned short numSqSum[20001];
const int sq20k = 1000;
//vector<list<pair<int,int> > > sqSums;

int main()
{
    //sqSums.resize(20001);
    for(int i = 1; i <= sq20k; ++i) {
        for(int j = i+1; j <= sq20k; ++j) {
            if(i*i+j*j<=20000){
                numSqSum[i*i+j*j]++;
                //sqSums[i*i+j*j].push_back(make_pair(i,j));
            }
        }
    }
    int a,b;
    in >> a >> b;
    int cnt = 0;
    for(int i = a; i <= b; ++i) {
        if(numSqSum[i]>=2) {
            out << i << '\n';
//            for(auto i2 = sqSums[i].begin(); i2 != sqSums[i].end();++i2) {
//                cout << i << ' ' << i2->first << ' ' <<i2->second << '\n';
//            }
            cnt++;
        }
    }
    if(cnt==0)out << cnt << '\n';
    return 0;
}
