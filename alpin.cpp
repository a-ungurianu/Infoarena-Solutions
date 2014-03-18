#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("alpin.in");
ofstream out("alpin.out");

struct Path {
	Path(size_t _pL,size_t _pC, size_t _len) {
		pL = _pL;
		pC = _pC;
		len = _len;
	}
	size_t pL,pC;
	unsigned len;
};

vector<vector<Path>> best;
vector<vector<unsigned>> mat;

void InitMats(size_t n) {
	best.resize(n);
	mat.resize(n);
	for(size_t i = 0; i < n; ++i) { 
		best[i].resize(n,Path(0,0,0));
		mat[i].resize(n,0);
	}
}

void ReadMat(size_t n) {
	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			in >> mat[i][j];
		}
	}
}

bool InBounds(size_t i, size_t j, size_t n) {
	return !((i < 0 || i >= n) || (j < 0 || j >= n));
}

const int dl[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

Path LongestRoadTo(size_t i, size_t j,size_t n) {
	if(best[i][j].len > 0) return best[i][j];

	Path maxPath(i,j,0);

	for(size_t k = 0; k < 4; ++k) {
		if(InBounds(i+dl[k], j+dc[k], n) && mat[i + dl[k]][j + dc[k]] < mat[i][j]){
			Path vecPath = LongestRoadTo(i+dl[k], j+dc[k],n);
			if(vecPath.len+1 > maxPath.len) {
				maxPath = Path(i+dl[k], j+dc[k], vecPath.len+1);
			}
		}
	}
	best[i][j] = maxPath;
	return best[i][j];
}

void printPath(Path path) {
	Path parent = best[path.pL][path.pC];
	if(parent.pC == path.pC && parent.pL == path.pL) {
		out << path.pL+1 << ' ' << path.pC + 1 << '\n';
	}
	else {
		printPath(parent);
		out << path.pL + 1 << ' ' << path.pC + 1 << '\n';
	}
}

int main() {
	size_t n;
	in >> n;
	InitMats(n);
	ReadMat(n);

	Path maxPath(0,0,0);
	Path outPath(0,0,0);


	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			if(LongestRoadTo(i,j,n).len > maxPath.len) {
				maxPath = LongestRoadTo(i,j,n);
				outPath = Path(i,j,maxPath.len+1);
			}
		}
	}
	out << outPath.len << '\n';
	printPath(outPath);
}
