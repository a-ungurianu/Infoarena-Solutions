#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream in ("padure.in");
ofstream out ("padure.out");

struct cel {
	size_t i,j;
};

const short dl[] = { 1, 0,-1, 0};
const short dc[] = { 0, 1, 0,-1};

int map[1002][1002];
long long costMap[1002][1002];
size_t n,m;


int main() {
	in >> n >> m;
	cel st,fn;
	in >> st.i >> st.j >> fn.i >> fn.j;
	for(size_t i = 1; i <= n; ++i) {
		for(size_t j = 1; j <= m; ++j) {
			in >> map[i][j];
			costMap[i][j]=-1;
		}
	}
	for(size_t i = 0; i <= n+1; ++i)
		costMap[i][0]=costMap[i][m+1]=-2;
	for(size_t i = 0; i <= m+1; ++i) 
		costMap[0][i]=costMap[n+1][i]=-2;

	costMap[st.i][st.j]=0;

	queue<cel> lee;
	for(lee.push(st);!lee.empty();lee.pop()) {
		cel c = lee.front();
		for(size_t k = 0; k < 4; k++) {
			size_t ci = c.i+dl[k];
			size_t cj = c.j+dc[k];
			if(map[c.i][c.j]!=map[ci][cj]) {
				if(costMap[ci][cj]!=-2&&(costMap[ci][cj]==-1||costMap[c.i][c.j]+1<costMap[ci][cj])){
					costMap[ci][cj]=costMap[c.i][c.j]+1;
					lee.push((cel){ci,cj});
				}
			}
			else {
				if(costMap[ci][cj]!=-2&&(costMap[ci][cj]==-1||costMap[c.i][c.j]<costMap[ci][cj])){
					costMap[ci][cj]=costMap[c.i][c.j];
					lee.push((cel){ci,cj});
				}
			}
		}
	}
	out << costMap[fn.i][fn.j] << '\n';
}
