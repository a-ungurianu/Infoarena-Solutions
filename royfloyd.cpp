#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("royfloyd.in");
ofstream out("royfloyd.out");

vector<vector<long long>> roadMat;

void InitMats(size_t n) {
	roadMat.resize(n);
	for(size_t i = 0; i < n; ++i) {
		roadMat[i].resize(n,0);
	}
}

void ReadPondMat(size_t n) {
	for(size_t i = 0; i < n; ++i)
		for(size_t j = 0; j < n; ++j)
			in >> roadMat[i][j];
}

void GenRoadMat(size_t n) {
	for(size_t k = 0; k < n; ++k)
		for(size_t i = 0; i < n; ++i)
			for(size_t j = 0; j < n; ++j)
				if(roadMat[i][k] && roadMat[k][j] && 
					(!roadMat[i][j] || roadMat[i][j] > roadMat[i][k] + roadMat[k][j]) && i != j)
						roadMat[i][j] = roadMat[i][k]+roadMat[k][j];
}

void PrintRoadMat(size_t n) {
	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j)
			out << roadMat[i][j] << ' ';
		out << '\n';
	}
}

int main() {
	size_t n;
	in >> n;
	InitMats(n);
	ReadPondMat(n);
	GenRoadMat(n);
	PrintRoadMat(n);
	
}
