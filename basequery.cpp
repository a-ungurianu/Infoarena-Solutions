#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>

typedef unsigned long long Big;

using namespace std;

Big proc[30][30][2048];
const char sym[]="0123456789ABCDEF";

unsigned convertFrom(char *s, unsigned base)
{
    unsigned res = 0;
    for(size_t i = 0, n = strlen(s); i < n; ++i)
    {
        if(isdigit(s[i]))
        {
            res = res*base+s[i]-'0';
        }
        else
        {
            res = res*base+s[i]-'A'+10;
        }
    }
    return res;
}

void strrev(char *s) {
    size_t n = strlen(s);
    for(size_t i = 0; i < n/2; ++i) {
        swap(s[i],s[n-i-1]);
    }
}

char *convertTo(unsigned nr, unsigned base)
{
    char *s = new char[100];
    size_t i = 0;
    while(nr)
    {
        s[i++]=sym[nr%base];
        nr/=base;
    }
    s[i]='\0';
    strrev(s);
    return s;
}

unsigned v[40000];

int main()
{
    ifstream in("basequery.in");
    size_t n;
    in >> n;

    for(size_t i = 0; i < n; ++i) {
        in >> v[i];
    }

    ofstream out("basequery.out");

    for(size_t i = 0; i < n; ++i)
        for(size_t b = 2; b <= 16; ++b) {
            char *s = convertTo(v[i],b);
            size_t nS = strlen(s);
            for(int j = 0; j < nS; ++j) {
                Big res = 0;
                for(int k = j; k < nS; ++k) {
                    if(isdigit(s[k])) {
                        res = res*b+(s[k]-'0');
                    }
                    else {
                        res = res*b+s[k]-'A'+10;
                    }
                    if(res>=1100) break;
                    proc[b-1][k-j+1][res]+=v[i];
                }
            }
            delete[] s;
        }
    size_t m;
    in >> m;
    for(size_t i = 0; i < m; ++i)
    {
        unsigned b;
        char scv[100];
        in >> b >> scv;
        unsigned cnv = convertFrom(scv,b);
        out << proc[b-1][strlen(scv)][cnv] << '\n';

    }
    return 0;
}
