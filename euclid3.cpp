#include <stdio.h>
#include <assert.h>
 
inline int gcd( int A, int B, int &X, int &Y )
{
    if (B == 0)
    {
        X = 1;
        Y = 0;
        return A;
    }
 
    int X0, Y0, D;
    D = gcd( B, A % B, X0, Y0 );
 
    X = Y0;
    Y = X0 - (A / B) * Y0;
    return D;
}
 
int main()
{
    freopen("euclid3.in", "rt", stdin);
    freopen("euclid3.out", "wt", stdout);
 
    int T;
    for (scanf("%d", &T), assert( T <= 100 ); T; T--)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
 
        assert( -1000000000 <= A && A <= 1000000000 );
        assert( -1000000000 <= B && B <= 1000000000 );
        assert( -2000000000 <= C && C <= 2000000000 && C != 0 );
        int D, X, Y;
        D = gcd( A, B, X, Y );
 
        if (C % D)
            printf("0 0\n");
        else
            printf("%d %d\n", X * (C / D), Y * (C / D));
    }
 
    return 0;
}
