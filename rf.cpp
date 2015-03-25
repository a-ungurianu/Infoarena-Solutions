#include <fstream>

using namespace std;

struct Road {
	unsigned distance;
	unsigned steps;
};

Road operator+(const Road& a, const Road& b) {
	return {a.distance+b.distance,a.steps+b.steps};
}

bool operator<(const Road& a, const Road& b) {
	if(a.distance == b.distance) {
		return a.steps > b.steps;
	}
	return a.distance < b.distance;
}

Road roads[256][256];

int main() {

	ifstream in("rf.in");
	unsigned n;
	in >> n;
	for(unsigned i = 0; i < n; ++i) {
		for(unsigned j = 0; j < n; ++j) {
			unsigned dist;
			in >> dist;
			if(i==j) {
				roads[i][j] = {dist,0};
			}
			else {
				roads[i][j] = {dist,1};
			}
		}
	}

	for(unsigned k = 0; k < n; ++k) {
		for(unsigned i = 0; i < n; ++i) {
			for(unsigned j = 0; j < n; ++j) {
				if(roads[i][k] + roads[k][j] < roads[i][j]) {
					roads[i][j] = roads[i][k] + roads[k][j];
				}
			}
		}
	}

	ofstream out("rf.out");
	for(unsigned i = 0; i < n; ++i) {
		for(unsigned j = 0; j < n; ++j) {
			out << roads[i][j].distance << ' ';
		}
		out << '\n';
	}
	for(unsigned i = 0; i < n; ++i) {
		for(unsigned j = 0; j < n; ++j) {
			out << roads[i][j].steps << ' ';
		}
		out << '\n';
	}
}