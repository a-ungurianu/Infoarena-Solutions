#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream in ("nextseq.in");
std::ofstream out ("nextseq.out");

size_t n,aSz,bSz;
std::vector<int> set,a,b;

void readVector(std::vector<int> &v, size_t sz)
{
	for (int i = 0; i < sz; ++i)
	{
		int t;
		in >> t;
		v.push_back(t);
	}
}

void norm(std::vector<int> &v)
{
	for(int i = 0; i < v.size(); i++ )
		v[i]=(std::lower_bound(set.begin(), set.end(),v[i])-set.begin())+1;
}

void subtr( std::vector<int> &a, const std::vector<int> &b)
{
	for(int i = 0, l = b.size(); i < l; i++)
	{
		if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=n;
		}
		a[i]=a[i]-b[i];
	}
	for(int i = b.size(); i < a.size(); i++)
	{
		if(a[i]<0)
		{
			a[i]+=n;
			a[i+1]--;
		}
	}
	while(a.back()==0)
		a.pop_back();
}

int convTo10(const std::vector<int> &nr)
{
	int res = 0;
	for(int i = nr.size()-1; i >= 0; i--)
		res=res*n+nr[i];
	return res;
}

int main()
{
	in >> n >> aSz >> bSz;
	readVector(set,n);
	readVector(a,aSz);
	readVector(b,bSz);
	std::sort(set.begin(), set.end());
	norm(a);
	norm(b);
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	subtr(b,a);
	int res = convTo10(b);
	if(res==0)out << 0;
	else out << res-1;
}
