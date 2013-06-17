#include <fstream>
#include <algorithm>

std::ifstream in ("aria.in"); 
std::ofstream out ("aria.out");

struct point
{
	double x,y;
};

int n;
point pts[100003];

int main()
{
	in >> n;
	for( int i = 0; i < n; i++)
	{
		double x,y;
		in >> x >> y;
		pts[i]=(point){x,y};
	}
	pts[n]=pts[0];

	double ar=0;
	for(int i = 0; i < n; i++)
	{
		ar+=(pts[i].x*pts[i+1].y-pts[i+1].x*pts[i].y)/2;
	}
	
	out.precision(6);
	out.setf(ios::fixed,ios::floatfield);
	out << abs(ar);
}
