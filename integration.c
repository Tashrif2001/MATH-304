#include <stdio.h>
#define f(x) ((x*x)+1)

int main()
{
    double a=0.0, b=2.0, h;
    int n=10;
    h=(b-a)/n;
    double x[n+1];
    double fx[n+1];
    x[0]=a;
    fx[0]=f(x[0]);
    for(int i=1; i<=n; i++)
    {
        x[i] = x[i-1]+h;
        fx[i] = f(x[i]);
    }
    double X=fx[0]+fx[n], I=0.0;
    for(int i=1; i<n; i++)
    I+=fx[i];
    I= ((X+2*I)*h)/2.0;
    printf("Integral value: %lf\n", I);
    return 0;
}
