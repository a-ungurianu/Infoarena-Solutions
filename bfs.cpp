#include <iostream>
#include <fstream>
#include <list>
#include <queue>

std::ifstream in ("bfs.in");
std::ofstream out ("bfs.out");

struct ndL
{
	unsigned int nd;
	unsigned int len;
};

std::list<unsigned int> adL[100001];
std::vector<int> lens(100001,-1);
unsigned int n,m,st;

int main()
{
	in >> n >> m >> st;
	for(int i = 0 ; i < m; i++)
	{
		unsigned int src,dest;
		in >> src >> dest;
		adL[src].push_back(dest);
	}
	std::queue<ndL> bf;
	ndL stN = (ndL){st,0};
	lens[st]=0;
	bf.push(stN);
	for(;!bf.empty();bf.pop())
	{
		for(auto it=adL[bf.front().nd].begin(); it!=adL[bf.front().nd].end(); it++)
		{
			if(lens[*it]==-1)
			{
				bf.push((ndL){*it,bf.front().len+1});
				lens[*it]=bf.front().len+1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		out << lens[i] << ' ';
	}
	out << '\n';
	return 0;
}
