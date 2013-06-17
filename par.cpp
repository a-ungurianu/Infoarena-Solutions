#include <fstream>
using namespace std;

ifstream in ("par.in");
ofstream out ("par.out");

int nrPD;
int n,nrInv;

int main()
{
	in >> n;
	if(n%2)
	{
		out << -1 << '\n';
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		char t;
		in >> t;
		if(t=='(')
				nrPD++;
		else
		{
			if(nrPD==0)
			{
				nrInv++;
				nrPD++;
			}
			else nrPD--;
		}
	}
	nrInv+=nrPD/2;
	out << nrInv << '\n';
	return 0;
}
