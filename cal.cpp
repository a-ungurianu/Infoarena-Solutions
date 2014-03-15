#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("cal.in");
ofstream out("cal.out");

struct Point
{
	int x,y;
};

unsigned manhDist(Point a, Point b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}

int main() {
	Point c;
	in >> c.x >> c.y;
	unsigned dist;
	in >> dist;
	size_t n;
	in >> n;

	unsigned counter = 0;

	for(size_t i = 0; i < n; ++i) {
		Point f;
		in >> f.x >> f.y;
		if(manhDist(c,f) == dist) {
			counter++;
		}
	}

	out << counter << '\n';
}
