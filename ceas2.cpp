#include <fstream>
#include <cstring>

std::ifstream in ("ceas2.in");
std::ofstream out ("ceas2.out");

int n,m;
char x[100003],y[100003];
char cod[256];

int main()
{
	f >> x >> y;
	n = strlen(x); m = strlen(y);
	bool ok;
	if(m == n)
	{
		ok = true;
		for(int i = 0; i < n && ok; ++i)
		{
			if(x[i] != y[i])
			{
				if(cod[x[i]] && (cod[x[i]] != y[i]))
					ok = false;
				else 
					cod[x[i]] = y[i];
			}
		}
	}
	else 
		ok = false;
	if(ok)
	{
		out << "DA\n";
		for(char c = 'a'; c <= 'z'; ++c)
			if(cod[c]) 
				out << c << ' ' << cod[c] << '\n';
	}
	else 
		out << "NU\n";
	return 0;
}
