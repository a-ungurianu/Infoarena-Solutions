#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <limits>

struct Point {
    int x;
    int y;
};

struct Segment {
    double length;
    double slope;
};


// NOTE: Always use this for float equality
bool fEqal(double d1, double d2) {
    return abs(d1-d2) < std::numeric_limits<double>::epsilon();
}

namespace std {
    template <> struct hash<Segment>
        {
            size_t operator()(const Segment & seg) const
            {
                return hash<double>()(seg.length) ^ hash<double>()(seg.slope);
            }
        };

    template <> struct equal_to<Segment>
        {
            bool operator()(const Segment & seg1, const Segment & seg2) const
            {
                return fEqal(seg1.slope, seg2.slope) && fEqal(seg1.length, seg2.length);
            }
        };
}

std::ifstream in("plagiat.in"); // Input file
std::ofstream out("plagiat.out"); // Output file

double getLength(Point p1, Point p2) {
    return std::sqrt((p2.x-p1.x)*(p2.x-p1.x) +
                     (p2.y-p1.y)*(p2.y-p1.y));
}

double getSlope(Point p1, Point p2) {
    return static_cast<double>(p2.y-p1.y) / (p2.x - p1.x);
}

Segment createSegment(Point p1, Point p2) {
    Segment seg;
    seg.length = getLength(p1,p2);
    seg.slope = getSlope(p1,p2);
    return seg;
}


int main() {

    unsigned iterations;

    in >> iterations;

    for(unsigned iterIndex = 0; iterIndex < iterations; iterIndex++) {
        unsigned pointCount;

        in >> pointCount;
        std::vector<Point> points(pointCount);

        std::unordered_map<Segment,unsigned char> segmentCount;

        for(Point &pnt:points) {
            in >> pnt.x >> pnt.y;
        }

        bool found = false;
        for(size_t firstPointIndex = 0; firstPointIndex < pointCount; ++firstPointIndex) {
            for (size_t secondPointIndex = firstPointIndex+1; secondPointIndex < pointCount; ++secondPointIndex) {
                Segment currentSegment = createSegment(points[firstPointIndex],points[secondPointIndex]);
                segmentCount[currentSegment] ++;
                if(segmentCount[currentSegment] >= 3) {
                    out << "DA\n";
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found)
            out << "NU\n";
    }


    return 0;
}