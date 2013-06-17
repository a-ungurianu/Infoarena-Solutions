#include <iostream>
#include <fstream>
using namespace std;

ifstream in ("fetite.in");
ofstream out ("fetite.out");

unsigned long long lastPetal(unsigned long long n)
{
	if(n==1)return 1;
	if(n&1)
	{
		return 2*lastPetal((n-1)/2)+1;
	}
	else
	{
		return 2*lastPetal(n/2)-1;
	}
}

unsigned long long lastPetalBin(unsigned long long n)
{
	unsigned long long power = 2;
	int e = 1;
	while(power <= n)
	{
		power*=2;
	 	e++;
	}
	power/=2;
	n-=power;
	n<<=1;
	n++;
	return n;
}

unsigned long long n;

int main()
{
	in >> n;
	out << lastPetal(n);
}
