#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream in("semipalindrom.in");
ofstream out("semipalindrom.out");

string solve(string nr) {
	if(nr.size()%2 == 0) {
		for(size_t i = 0,n = nr.size(); i < n/2; ++i)
			if(nr[i]!=nr[i+n/2])return nr.substr(0,1);
	}
	else {
		for(size_t i = 0,n = nr.size(); i < n/2; ++i)
			if(nr[i]!=nr[i+n/2+1])return nr.substr(0,1);
	}
	return nr.substr(0,nr.size()/2);
}

int main() {
	string nr;
	in >> nr;
	out << solve(nr);
}
