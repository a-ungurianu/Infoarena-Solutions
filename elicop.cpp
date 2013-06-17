#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("elicop.in");
ofstream out ("elicop.out");
int n,m,eNtAf;
bool fieldMap[100][100];
char wrongElic[42];

int abs(int x)
{
	if( x < 0 )return -x;
	return x;
}
int min(int a,int b)
{
	if(a > b)return b;
	return a;
}

void solve(int k)
{
	int x1,x2,y1,y2,sw;
	in >> x1 >> y1 >> x2 >> y2 >> sw;
	int xOff=min(x1,x2);
	int yOff=min(y1,y2);
	int sX = abs(x2-x1);
	int sY = abs(y2-y1);
	int zAf=0;
	int zT = 0;
	if(x2-x1==y2-y1)
	{
		if(sw==1)
		{
			for(int i = 0; i <= sX; i++)
				for(int j = sY; j >= i; j--)
				{
					zT++;
					if(fieldMap[i+xOff-1][j+yOff-1]==0)
						zAf++;
				}
		}
		else
		{
			for(int i = 0; i <= sX; i++)
				for(int j = 0; j <= i; j++)
				{
					zT++;
					if(fieldMap[i+xOff-1][j+yOff-1]==0)
						zAf++;
				}
		}
	}
	else
	{
		if(sw == 1)
		{
			for(int i = 0; i <= sX; i++)
				for(int j = 0; j <= sY-i; j++)
				{
					zT++;
					if(fieldMap[i+xOff-1][j+yOff-1]==0)
						zAf++;
				}
		}
		else
		{
			for(int i = 0; i <= sX; i++)
				for(int j = sY-i; j <= sY; j++)
				{
					zT++;
					if(fieldMap[i+xOff-1][j+yOff-1]==0)
						zAf++;
				}
		}
	}
	if(zAf==0)eNtAf++;
	else if(zT/zAf<2)wrongElic[++wrongElic[0]]=k;
}


int main()
{
	in >> n >> m;
	for( int i = 0; i < n; i++)
		for( int j = 0; j < m; j++)
			in >> fieldMap[i][j];
	int k;
	in >> k;
	for(int e = 1; e <= k; e++)
	{
		solve(e);
	}
	out << eNtAf << '\n';
	for(int i = 0; i <= wrongElic[0];i++)
		out << int(wrongElic[i]) << ' ';
}
