#include <fstream>
#include <iostream>
using namespace std;

ifstream in ("curcubeu.in");
ofstream out ("curcubeu.out");
const size_t NMax = 1000001;

unsigned int a[NMax],b[NMax],c[NMax],sol[NMax],nextEmpty[NMax];

int main()
{
	int n;
	in >> n >> a[1] >> b[1] >> c[1];
	nextEmpty[1]=1;
	for(int i = 2; i < n; i++)
	{
		a[i] = (1LL*a[i-1]*i)%n;
		b[i] = (1LL*b[i-1]*i)%n;
		c[i] = (1LL*c[i-1]*i)%n;
		nextEmpty[i]=i;
	}

	for(int i = n-1; i >= 1; i--)
	{
		int st = min(a[i],b[i]);
		int fn = max(a[i],b[i]);
		int j = st;
		while(j <= fn)
		{
			if(nextEmpty[j]==j)
			{
				sol[j]=c[i];
				nextEmpty[j]=fn+1;
				j++;
			}
			else
			{
				int newJ = nextEmpty[j];
				nextEmpty[j] = fn+1;
				j = newJ;
			}
		}

	}
	for(int i = 1; i < n; i++)
		out << sol[i] << '\n';
}
