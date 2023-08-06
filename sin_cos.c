#include <stdio.h>
#include <math.h>
#define pi 3.14159265

int main()
{
    int n = 100;
    double a = 0, b = 2 * pi, h, p;
    h = (b - a) / n;

    double x[n + 1];
    double fx[n + 1];
    double dfx[n+1];

    printf("\"x\",\"sin(x)\",\"cos(x)\"\n");

    p = a;
    for (int i = 0; i <= n; i++)
    {
        x[i] = p;
        fx[i] = sin(p);
        p += h;
    }
    for(int i=0; i<n; i++)
    dfx[i] = (fx[i+1]-fx[i])/h;
    
    for(int i=0; i<n; i++)
    printf("%lf, %lf, %lf\n", x[i], fx[i], dfx[i]);
}
