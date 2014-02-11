#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<double,double> Point;


ifstream in("infasuratoare.in");
ofstream out("infasuratoare.out");

vector<Point> points;

double cross(const Point &O, const Point &A, const Point &B) {
	return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

int main() {
	size_t n;
	in >> n;
	points.resize(n);
	for(size_t i = 0; i < n; ++i) {
		double x,y;
		in >> x >> y;
		points[i]=Point(x,y);
	}

	vector<Point> hull;
	hull.resize(2*n);

	sort(points.begin(), points.end());

	size_t k = 0;

	for(size_t i = 0; i < n; ++i) {
		while(k >= 2 && cross(hull[k-2],hull[k-1],points[i]) < 0) k--;
		hull[k++] = points[i];
	}

	for(int i = n-2, t = k+1; i >= 0; --i) {
		while(k >= t && cross(hull[k-2],hull[k-1],points[i]) < 0) k--;
		hull[k++] = points[i];
	}

	out << k-1 << '\n';
	out << setprecision(6) << fixed;
	for(size_t i = 0; i < k-1; ++i)
		out << hull[i].first << ' ' << hull[i].second << '\n';
}
