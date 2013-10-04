#include <fstream>
#include <algorithm>

using namespace std;

ifstream in ("reuniune.in");
ofstream out ("reuniune.out");

typedef long long int int_64;

struct Rect {
    int_64 x1;
    int_64 y1;
    int_64 x2;
    int_64 y2;
    void normalize() {
        if(x1<=x2 && y1 <= y2){
            int_64 aux = x1;
            x1 = x2;
            x2 = x1;
            aux = y1;
            y1 = y2;
            y2 = aux;
        }
    }
    int_64 per() {
        return 2*(x2-x1+y2-y1);
    }
    int_64 area() {
        return (x2-x1)*(y2-y1);
    }
};

Rect Intersect(Rect r1, Rect r2) {
    Rect res;
    res.x1 = max(r1.x1, r2.x1);
    res.x2 = min(r1.x2, r2.x2);
    res.y1 = max(r1.y1, r2.y1);
    res.y2 = min(r1.y2, r2.y2);

    if(res.x1 > res.x2 || res.y1 > res.y2)
        res.x1 = res.x2 = res.y1 = res.y2 = 0;

    return res;
}

int main()
{
    Rect v[3];

    for(int_64 i = 0; i < 3; ++i) {
        in >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    }

    int_64 arTot = v[0].area()+v[1].area()+v[2].area()-
                (Intersect(v[0],v[1]).area()+Intersect(v[0],v[2]).area()+Intersect(v[1],v[2]).area()) +
                Intersect(Intersect(v[0],v[1]),v[2]).area();
    int_64 perTot = v[0].per()+v[1].per()+v[2].per()-
                 (Intersect(v[0],v[1]).per()+Intersect(v[0],v[2]).per()+Intersect(v[1],v[2]).per()) +
                 Intersect(Intersect(v[0],v[1]),v[2]).per();
    out << arTot << ' ' << perTot << '\n';
}
