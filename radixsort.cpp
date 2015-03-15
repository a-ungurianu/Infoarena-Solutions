#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

vector<unsigned> sort_by_byte(const vector<unsigned> &data, unsigned byte) {
	vector<unsigned> result(data.size());
	vector<unsigned> count(256,0);
	auto key = [byte] (unsigned x) -> unsigned {return (x >> (byte*8)) & 0xFF;};

	for(unsigned val:data) {
		count[key(val)]++;
	}
	unsigned total = 0;
	for(size_t i = 0; i < 256; ++i) {
		unsigned oldCount = count[i];
		count[i] = total;
		total += oldCount;
	}

	for(unsigned val:data) {
		result[count[key(val)]] = val;
		count[key(val)]++;
	}

	return result;
}

vector<unsigned> sort(vector<unsigned> data) {
	for(size_t i = 0; i < 4; ++i)
		data = sort_by_byte(data,i);
	return data;
}

int main() {

	ifstream in("radixsort.in");
	unsigned long long n,a,b,c;

	in >> n >> a >> b >> c;

	vector<unsigned> data(n);
	data[0] = b;

	for(int i = 1; i < n; ++i) {
		data[i] = (a*data[i-1] + b) % c;
	}

	data = sort(data);

	ofstream out("radixsort.out");
	for(size_t i = 0; i < n; i += 10) {
		out << data[i] << ' ';
	}
}