#include <fstream>
#include <map>
#include <cstring>
using namespace std;
ifstream in ("texttrim.in"); ofstream out ("texttrim.out");
 
map<char, int> cost;
char txt[1000001];
int main() {
    in >> cost[' '];
    for(char i = 'a'; i <= 'z'; i++)
        in >> cost[i];
    in.ignore();
    in.getline(txt, 1000000);
    int w;
    in >> w;
    int curW = 0;
    int i = 0;
    int txtSz = strlen(txt);
    while(curW <= w && i < txtSz)
        curW += cost[txt[i++]];
 
    if(i == txtSz) {
        out << txt;
        return 0;
    }
    curW += 3;
    i--;
    while(curW > w&&i>=0)
    {
      curW-=cost[txt[i]];
      txt[i--]='\0';
    }
    out << txt << "...";
}
