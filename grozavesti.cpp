#include <fstream>
#include <vector>

using namespace std;

struct Inversion {
	Inversion() = default;
	Inversion(unsigned from, unsigned to) :
		from(from), to(to) {}
	unsigned from;
	unsigned to;
};

vector<Inversion> get_inversions(vector<unsigned> &data) {
	vector<Inversion> inversions;
	for(int i = 0; i < data.size(); ++i) {
		unsigned min_val = data[i];
		Inversion min_inv;
		for(int j = i+1; j < data.size(); ++j) {
			if(data[j] < min_val) {
				min_val = data[j];
				min_inv = {i,j};
			}
		}
		if(min_val != data[i]) {
			swap(data[min_inv.from],data[min_inv.to]);
			inversions.push_back(min_inv);
		}
	}
	return inversions;
}

void print_inversions(ostream &out, vector<Inversion> inversions) {
	out << 2*inversions.size() << '\n';
	for(Inversion inversion:inversions) {
		out << "C " << inversion.from+1 << ' ' << inversion.to+1 << '\n';
		out << "L " << inversion.from+1 << ' ' << inversion.to+1 << '\n';
	}
}

int main() {
	ifstream in("grozavesti.in");
	ofstream out("grozavesti.out");

	unsigned n;
	in >> n;

	vector<unsigned> diagonal(n);

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int val;
			in >> val;
			if(i == j) {
				diagonal[i] = val;
			}
		}
	}
	print_inversions(out,get_inversions(diagonal));

	return 0;
}