#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;
ifstream in ("lacuri.in");
ofstream out ("lacuri.out");

const short dl[] = {0,1,0,-1};
const short dc[] = {-1,0,1,0};
const short dl2[] = {-1,-1, 0, 1, 1, 1, 0,-1};
const short dc2[] = {0 , 1, 1, 1, 0,-1,-1,-1};

struct cel {
	int i,j;
};

int map[102][102];
int n;
int maxI,maxJ,minJ;
int cellCnt = 0;
bool allLakesAreSq = true;
bool isGoodLake = true;


void fill(int i,int j) {
	map[i][j]=2;
	cellCnt++;
	if(maxI == i) {
		if(maxJ < j) {
			maxJ = j;
		}
	}
	if(maxI < i) {
		maxI = i;
		maxJ = j;
	}

	if(minJ > j) {
		minJ = j;
	}

	for(int k = 0; k < 4; k++) {
		int ci,cj;
		ci = i+dl[k];
		cj = j+dc[k];
		if(map[ci][cj]==1) {
			fill(ci,cj);
		}
	}
}

void fill2(int i, int j) {
	map[i][j]=3;
	for(int k = 0; k < 8; k++) {
		int ci,cj;
		ci = i+dl2[k];
		cj = j+dc2[k];
		if(map[ci][cj]==1) {
			map[ci][cj]=3;
			isGoodLake = false;
			allLakesAreSq = false;
		}
	}
	for(int k = 0; k < 4; k++) {
		int ci,cj;
		ci = i+dl[k];
		cj = j+dc[k];
		if(map[ci][cj]==2) {
			fill2(ci,cj);
		}
	}
}

bool isSquare(int i, int j) {
	maxI = i, maxJ = j,minJ=j;
	isGoodLake = true;
	cellCnt = 0;
	fill(i,j);
	fill2(i,j);
	if(isGoodLake && minJ == j && maxI-i==maxJ-j && (maxI-i+1)*(maxJ-j+1)==cellCnt) {
		cout << i << ' ' << j << ' ' << maxI << ' ' << maxJ << '\n';
		return true;
	}
	return false;
}


int main() {
	in >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			in >> map[i][j];
		}
	}

	for(int i = 0; i <= n+1; ++i)
		map[0][i]=map[i][0]=map[n+1][i]=map[i][n+1]=-1;

	int sqrCnt = 0;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(map[i][j] == 1){
				if(isSquare(i,j)) {
					sqrCnt++;
				}
				else {
					allLakesAreSq = false;
				}
			}
		}
	}
	out << sqrCnt << '\n';
	if(allLakesAreSq) {
		queue<cel> lee;
		map[1][1]=4;
		for(lee.push((cel){1,1});!lee.empty(); lee.pop()) {
			cel c = lee.front();
			for(int k = 0; k < 4; k++) {
				int ci = c.i + dl[k];
				int cj = c.j + dc[k];
				if(map[ci][cj]==0 && map[ci][cj]<=map[c.i][c.j]+1) {
					lee.push((cel){ci,cj});
					map[ci][cj]=map[c.i][c.j]+1;
				}
			}
		}

		int i=n,j=n;
		stack<cel> road;
		road.push((cel){i,j});
		while(i!=1||j!=1) {
			for(int k = 0; k < 4; k++) {
				int ci = i + dl[k];
				int cj = j + dc[k];
				if(map[ci][cj]==map[i][j]-1) {
					road.push((cel){ci,cj});
					i = ci;
					j = cj;
					break;
				}
			}
		}
		while(!road.empty()) {
			cel c = road.top();
			out << c.i << ' ' << c.j << '\n';
			road.pop();
		}
	}
	return 0;
}
