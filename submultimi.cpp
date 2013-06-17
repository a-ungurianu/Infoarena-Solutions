#include <fstream>
using namespace std;
ifstream in ("submultimi.in");
ofstream out ("submultimi.out");

int main()
{
	unsigned int n;
	in >> n;
	for(unsigned int i = 1; i < (1 << n); i++)
	{
		int j = 1;
		unsigned int aux = i;
		while(aux)
		{
			if(aux&1)out << j << ' ';
			j++;
			aux >>= 1;
		}
		out << '\n';
	}
}
