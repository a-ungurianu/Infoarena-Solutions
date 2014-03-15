#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<vector<unsigned>> InitTable(size_t n) {
	vector<vector<unsigned>> t(n);
	for(size_t i = 0; i < n; ++i) 
		t[i].resize(n);
	return t;
}

int main() {
	freopen("sah.in","r",stdin);
	size_t n;
	scanf("%d",&n);
	vector<vector<unsigned>> table = InitTable(n);

	for(size_t i = 0; i < n; ++i)
		table[0][i] = table[1][i] = 1;

	unsigned zone = 2;
	for(size_t i = 2; i < n; i+=2) {
		for(size_t j = 0; j < n; ++j) {
			if( j < n/2+i/2 ) {
				table[i][j] = table[i+1][j] = zone;
			}
			else {
				table[i][j] = table[i+1][j] = zone+1;
			}
		}
		zone+=2;
	}
	freopen("sah.out","w",stdout);
	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
}
