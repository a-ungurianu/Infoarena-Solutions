#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
ifstream in("aparitii.in");
ofstream out("aparitii.out");

unordered_map<unsigned,unsigned> fr;

int main() {
	unsigned n,k;
	in >> n >> k;

	for(size_t i = 0; i < n; ++i) {
		unsigned a;
		in >> a;
		if(fr.count(a))
			fr[a]++;
		else 
			fr[a]=1;
	}

	for(const auto &i:fr) {
		if(i.second%k!=0) {
			out << i.first << '\n';
			return 0;
		}
	}

	return -1;

}
