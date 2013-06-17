#include <fstream>

typedef long long ll;

std::ifstream in ("classictask.in");
std::ofstream out ("classictask.out");

ll mod;
ll produs ( ll x, ll y )
{
	ll s = 0;
	for( ll i=x; y; y >>= 1 )
	{
		if(y & 1) 
			s = (s + i)%mod;
		i = (i+i)%mod;
	}
	return s;
}

int main()
{
	ll a,b;
	f >> a >> b >> mod;
	ll p = 1;
	for( ll i=a; b; b >>= 1 )
	{
		if(b & 1) p = produs(p,i);
		i=produs(i,i);
	}

	out << p << '\n';

	return 0;
}
