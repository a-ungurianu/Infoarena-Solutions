#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


ifstream in("noroc.in");
ofstream out("noroc.out");

int main() {

    unsigned x,m;

    in >> x >> m;

    double res = double(1) - double(x)/m;
    if(res < 0.0f) res = 0.0f;
    out << fixed << setprecision(7) << res << '\n';
}