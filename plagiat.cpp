#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <limits>

struct Point {
    int x;
    int y;
};

double getLength(Point p1, Point p2) {
    return std::sqrt((p2.x-p1.x)*(p2.x-p1.x) +
                     (p2.y-p1.y)*(p2.y-p1.y));
}

// Calculate the slope of a segment defined by two points
double getSlope(Point p1, Point p2) {
    return static_cast<double>(p2.y-p1.y) / (p2.x - p1.x);
}

struct Segment {
    double length;
    double slope;

    //Create a segment given two points
    Segment(const Point & p1, const Point & p2) :
        length(getLength(p1,p2)),
        slope(getSlope(p1,p2)) {}

};


// NOTE: Not absolutly correct, but works for our purposes
bool fEqal(double d1, double d2) {
    return std::abs(d1-d2) < std::numeric_limits<double>::epsilon();
}

// These specializations are needed for unordered_map<Segment> to work
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

        bool found = false; //Have we found a triangle pair?
        for(size_t firstPointIndex = 0; firstPointIndex < pointCount; ++firstPointIndex) {
            for (size_t secondPointIndex = firstPointIndex+1; secondPointIndex < pointCount; ++secondPointIndex) {

                Segment currentSegment(points[firstPointIndex],points[secondPointIndex]);
                segmentCount[currentSegment] ++;
                if(segmentCount[currentSegment] >= 3) {  // If we found the same segment 3 times,
                    out << "DA\n";                       // we found a pair of triangles
                    found = true;
                    break;
                }
            }
            if(found) break; // Break out if triangle pair has been found.
        }
        if(!found)
            out << "NU\n";
    }

    return 0;
}