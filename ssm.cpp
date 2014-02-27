#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;
ifstream in("ssm.in");
ofstream out("ssm.out");

vector<int> minSums;

vector<int> ReadData() {
	size_t n;
	in >> n;
	vector<int> sms(n);
	in >> sms[0];
	for(size_t i = 1; i < n; ++i) {
		in >> sms[i];
		sms[i]+=sms[i-1];
	}

	return sms;
}

int main() {
	vector<int> sums = ReadData();

	int maxVal = int(-2e9);
	int minVal = 0;
	size_t start,end,idx;

	for(size_t i = 1; i < sums.size(); ++i) {
		if(sums[i] - minVal > maxVal) {
			maxVal = sums[i] - minVal;
			start = idx+2;
			end = i+1;
		}
		if(minVal > sums[i]){
			minVal = sums[i];
			idx = i;
		}
	}

	out << maxVal << ' ' << start << ' ' << end << '\n';
}
