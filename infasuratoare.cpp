#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<double,double> Point;


ifstream in("infasuratoare.in");
ofstream out("infasuratoare.out");

vector<Point> points;

class ConvexHullAlg {

public:
	ConvexHullAlg() {}
	ConvexHullAlg(vector<Point> pts)
		{
			points = pts;
			nPoints = pts.size();
		}
	void addPoint(double x, double y) {
		points.push_back(Point(x,y));
	}

	vector<Point> getHull() {
		vector<Point> hull;
		hull.resize(2*nPoints);

		sort(points.begin(), points.end());

		size_t k = 0;

		for(size_t i = 0; i < nPoints; ++i) {
			while(k >= 2 && turn(hull[k-2],hull[k-1],points[i]) == -1) k--;
			hull[k++] = points[i];
		}

		for(int i = nPoints-2, t = k+1; i >= 0; --i) {
			while(k >= t && turn(hull[k-2],hull[k-1],points[i]) == -1) k--;
			hull[k++] = points[i];
		}
		hull.resize(k-1);

		return hull;
	}

private:
	int turn(const Point &O, const Point &A, const Point &B) {
		double rot = (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
		if(rot > 0) return 1;
		else if(rot == 0) return 0;
		else return -1;
	}

	size_t nPoints;
	vector<Point> points;
};

int main() {
	size_t n;
	in >> n;
	points.resize(n);
	for(size_t i = 0; i < n; ++i) {
		double x,y;
		in >> x >> y;
		points[i]=Point(x,y);
	}

	cerr << "Works";

	ConvexHullAlg hullSolve(points);
	vector<Point> hull = hullSolve.getHull();

	out << hull.size() << '\n';
	out << setprecision(6) << fixed;
	for(size_t i = 0; i < hull.size(); ++i)
		out << hull[i].first << ' ' << hull[i].second << '\n';
}
