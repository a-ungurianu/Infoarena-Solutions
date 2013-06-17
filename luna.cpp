#include<fstream>
using namespace std;
ifstream in ("luna.in"); ofstream out ("luna.out");
int n, m;
bool vis[5002];
int dp[2502][52], hMap[52][52], map[52][52];
int main() {
    in >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            in >> map[i][j];
            vis[map[i][j]] = true;
        }
    for(int j = 1; j <= m; ++j)  hMap[n][j] = 1;
    for(int i = n - 1; i >= 1; --i)
        for(int j = 1; j <= m; ++j)
                    if(map[i][j] == map[i+1][j]) hMap[i][j] = hMap[i+1][j]+1; else hMap[i][j] = 1;
    for(int i = 1; i <= n; ++i) {
    int hRowMin=25232;
        for(int k = 1; k <= m; ++k) {
            int p = k;
            while(map[i][p] == map[i][p+1]) ++p;
            int vm = hMap[i][k];
            int t = map[i][k];
            for(int r = k; r <= p; ++r) {
                if(hMap[i][r] < vm) vm = hMap[i][r];
                int j = r - k + 1;
                if(dp[t][j] < vm) dp[t][j] = vm;
            }
            if(vm<hRowMin)hRowMin=vm;
        }
        i+=hRowMin-1;
    }
  int k;
    in >> k;
    int t,a,b;
    for(int i = 1; i <= k; ++i) {
        in >> t >> a >> b;
        if(vis[t]) {
            if(a > 50 || b > 50) out << "Cererea nu poate fi satisfacuta!\n";
            else {
                if(a <= dp[t][b] || b <= dp[t][a]) out << "Cererea poate fi satisfacuta!\n";
                else out << "Cererea nu poate fi satisfacuta!\n";
            }
        }
        else out << "Tara de provenienta nu are parcele pe Luna!\n";
    }
    out.close(); return 0;
}
