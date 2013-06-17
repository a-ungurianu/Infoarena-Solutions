#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream in ("algsort.in"); 
std::ofstream out ("algsort.out");

int n;

int main()
{

	std::vector<int> nrs;
	in >> n;
	for(int i = 0; i < n; i++)
	{
		int t;
		in >> t;
		nrs.push_back(t);
	}
	
	std::sort(nrs.begin(),nrs.end());
	
	for(int i = 0; i < n; i++)
	{
		out << nrs[i] << ' ';
	}
	out << '\n';
	
	return 0;
}
