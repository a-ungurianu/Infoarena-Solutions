#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
  
ifstream in("pariuri.in");
ofstream out("pariuri.out");
  
unordered_map<unsigned,int> list;
  
int main() {
    int n;
    in >> n;
    for(int i = 0; i < n; ++i) {
        int m;
        in >> m;
        for(int j = 0; j < m; ++j) {
            int tp,val;
            in >> tp >> val;
            if(list.count(tp))
                list[tp]+=val;
            else
                list[tp]=val;
        }
    }
    out << list.size() << '\n';
    for(auto it = list.cbegin(); it!=list.cend();++it){
        out << it->first << ' ' << it->second << ' ';
    }
    out << '\n';
    return 0;
}
