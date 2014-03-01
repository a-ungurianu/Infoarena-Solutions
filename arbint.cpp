#include <iostream>
#include <fstream>

using namespace std;
ifstream in("arbint.in");
ofstream out("arbint.out");

int intArb[2000000];

inline void update(size_t nod, size_t st, size_t dr, size_t i ,unsigned val) {
	if(st <= i && i <= dr) {
		if(st!=dr) {
			size_t mij = (st+dr)>>1;
			if(i <= mij)
				update(nod<<1,st,mij,i,val);
			if(i > mij)
				update((nod<<1)+1,mij+1,dr,i,val);
            intArb[nod] = max(intArb[nod<<1],intArb[(nod<<1)+1]);
		}
		else {
			intArb[nod] = val;
		}
	}
}

inline unsigned query(size_t nod,size_t st, size_t dr, size_t a, size_t b) {
    if(a <= st && dr <= b)
        return intArb[nod];
    else {
        size_t mij = (st+dr)>>1;
        unsigned maxVal = 0;
        if(a <= mij)
            maxVal = max(maxVal, query(nod<<1,st,mij,a,b));
        if(b > mij)
            maxVal = max(maxVal, query((nod<<1)+1,mij+1,dr,a,b));
        return maxVal;
    }
}

int main() {
	size_t n,m;
	in >> n >> m;
	for(int i = 0; i < n; ++i) {
		unsigned t;
		in >> t;
		update(1,0,n-1,i,t);
	}
    for(int i = 0; i < m; ++i) {
        unsigned a,b;
        char t;
        in >> t >> a >> b;
        if(t == '0') {
            out << query(1,0,n-1,a-1,b-1) << '\n';
        }
        else {
            update(1,0,n-1,a-1,b);
        }
    }
}
