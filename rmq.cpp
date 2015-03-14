#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class RangeMinimumQueryable {
public:
	RangeMinimumQueryable(const vector<unsigned> &data) :
		log_size(ceil(log(data.size())/log(2))),
		size(data.size()),
		rmq_data(size,vector<unsigned>(log_size))
	{
		for(int i = 0; i < size; ++i) {
			rmq_data[i][0] = data[i];
		}

		for(int k = 1; k < log_size; ++k) {
			for(int i = 0; i + pow2(k) - 1 < size; ++i) {
				rmq_data[i][k] = min(rmq_data[i][k-1],rmq_data[i+pow2(k-1)][k-1]);
			}
		}
	}

	unsigned query(unsigned i, unsigned j) {
		unsigned k = floor(log(j-i+1)/log(2));
		return min(rmq_data[i][k],rmq_data[j-pow2(k)+1][k]);
	}

private:

	unsigned pow2(unsigned n){
		return 1 << n;
	}

	unsigned size;
	unsigned log_size;
	vector<vector<unsigned>> rmq_data;
};

int main() {

	ifstream in("rmq.in");

	unsigned no_elements, no_queries;
	in >> no_elements >> no_queries;
	vector<unsigned> data(no_elements);

	for(int i = 0; i < no_elements; ++i) {
		in >> data[i];
	}

	RangeMinimumQueryable solver(data);


	ofstream out("rmq.out");

	for(int i = 0; i < no_queries; ++i) {
		unsigned a,b;
		in >> a >> b;
		out << solver.query(a-1,b-1) << '\n';
	}

	
}