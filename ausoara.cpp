#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in ("ausoara.in");
ofstream out ("ausoara.out");

vector<vector<unsigned>> data;
vector<unsigned> ind;
vector<unsigned> sol;

bool cmp(const vector<unsigned> &a,const vector<unsigned> &b) {
	return a.size()<b.size();
}

int main() {
	int n;
	in >> n;
	data.resize(n);
	ind.resize(n);
	for(int i = 0; i < n; ++i) {
		int sz;
		in >> sz;
		data[i].resize(sz);
		for(int j = 0; j < sz; ++j) {
			in >> data[i][j];
		}
	}

	sort(data.begin(), data.end(),cmp);
	for(ind[0] = 0; ind[0] < data[0].size(); ++ind[0]) {
		int val = data[0][ind[0]];
		bool isEq = true;
		for(int j = 1; j < n; j++) {
			for(;ind[j]<data[j].size()&&data[j][ind[j]]<val;ind[j]++);
			if(data[j][ind[j]]!=val) {
				isEq = false;
			}
		}
		if(isEq){
			sol.push_back(val);
			for(int i = 1; i < n; ++i)ind[i]++;
		}
	}
	out << sol.size() << ' ';
	for(int i = 0; i < sol.size(); ++i)
		out << sol[i] << ' ';
}
