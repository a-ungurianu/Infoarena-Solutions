#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream in ("cautbin.in");
ofstream out ("cautbin.out");

vector<int> v;

int n;

int main() 
{
	in >> n;
	v.resize(n);
	for(int i = 0; i < n; ++i)
		in >> v[i];
	int m;
	in >> m;
	while(m--) {
		int t,x;
		in >> t >> x;
		switch(t) {
			case 0:{
				int i = upper_bound(v.begin(), v.end(),x) - v.begin() - 1; 
				if(i==n||v[i]!=x)
					out << -1 << '\n';
				else 
					out << i+1 << '\n';
				}
				break;
			case 1:
				out << lower_bound(v.begin(), v.end(),x+1)-v.begin() << '\n';
				break;
			case 2:
				out << upper_bound(v.begin(), v.end(),x-1)-v.begin() + 1 << '\n';
				break;
		}
	}
	return 0;
}
