#include <iostream>
#include <fstream>

std::ifstream in ("litere.in");
std::ofstream out ("litere.out");

unsigned int frLit[26];

int main()
{
	int n;
	in >> n;
	int nrInv = 0;
	for(int i = 0; i < n; i++)
	{
		char t;
		in >> t;
		t-='a';
		frLit[t]++;
		for(int j = t+1; j < 26; j++)
			nrInv+=frLit[j];
	}
	out << nrInv;
}
