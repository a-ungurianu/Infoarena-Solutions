#include <cstdio>
#include <cstring>
#include <algorithm>

char s[100010];
char *p=s;
char operand[4][4] = {"Mm", "*/", "^", ""};
const long hmax = 1;

long operatie(long x, long y, char c) {
    switch ( c ) {
        case 'm': return std::min(x,y);
        case 'M': return std::max(x,y);
        case '*': return x*y;
        case '/': return x/y;
    }
    return 0;
}

long eval(long);

long element() {
    long r=0;
    if ( *p == '(' ) {
        ++p; r = eval(0); ++p;
    } else {
        while ( strchr("0123456789", *p) )
            r = r*10 + *(++p-1) - '0';
    }
    return r;
}

long eval(long h) {
    long r = (h==hmax)?element():eval(h+1);
    while ( strchr(operand[h], *p) )
        r = operatie(r, eval(h+1), *(++p-1));
    return r;
}


int main() {
    fgets(s, 100010, fopen("emm.in", "r"));
    fprintf(fopen("emm.out", "w"), "%ld\n", eval(0));
    return 0;
}
