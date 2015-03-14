#include <fstream>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	ifstream in("secventa.in");

	int n,k;
	in >> n >> k;

	vector<int> values(n+1);

	for(int i = 1; i <= n; ++i) {
		in >> values[i];
	}

	int max_value = -32012;
	int max_ind = -1;

	deque<int> dq;

	for(int i = 1; i <= n; ++i) {
		while(!dq.empty() && values[dq.back()] > values[i])
			dq.pop_back();

		dq.push_back(i);

		while(dq.front() <= i-k) {
			dq.pop_front();
		}

		if(i >= k && values[dq.front()] > max_value) {
			max_value = values[dq.front()];
			max_ind = i;
		}
	}
	ofstream out("secventa.out");
	out << max_ind-k+1 << ' ' << max_ind << ' ' << max_value << '\n';

	return 0;
}