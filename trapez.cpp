#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct Point {
	double x,y;
};

double slope(Point p1, Point p2) {
	return (p1.y - p2.y)/(p1.x-p2.x);
}

typedef unsigned long long BigUnsigned;

BigUnsigned pair_count(BigUnsigned k) {
	return (k*(k-1))/2;
}

int main() {

	ifstream in("trapez.in");
	unsigned n;
	in >> n;

	vector<Point> points(n);

	for(Point &point:points) {
		in >> point.x >> point.y;
	}

	in.close();

	vector<double> slopes;
	for(size_t i = 0; i < n; ++i) {
		for(size_t j = i+1; j < n; ++j) {
			slopes.push_back(slope(points[i],points[j]));
		}
	}

	sort(slopes.begin(),slopes.end());

	double currentSlope = slopes[0];
	BigUnsigned count = 1;
	
	BigUnsigned total = 0;

	for(size_t i = 1; i < slopes.size(); ++i) {
		if(currentSlope == slopes[i]) {
			count++;
		}
		else {
			total += pair_count(count);
			currentSlope = slopes[i];
			count = 1;
		}
	}

	ofstream out("trapez.out");

	out << total << '\n';

	return 0;
}