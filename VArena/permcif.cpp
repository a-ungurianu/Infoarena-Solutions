#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

ifstream in ("permcif.in");
ofstream out("permcif.out");

string CyclePerm(string a) {
	return a.substr(1) + a[0];
}


bool PermCif(string a,string b){
	for(size_t i = 0; i < a.size(); ++i) {
		if(atoi(a.c_str())==atoi(b.c_str()))return true;
		a = CyclePerm(a);
	}
	return false;
}

int main() {
	char a[11],b[11];
	for(size_t i = 0; i < 5; ++i) {
		in >> a >> b;
		out << PermCif(a,b) << '\n';
	}	
}
