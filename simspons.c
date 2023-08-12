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
    double X=fx[0]+fx[n], I=0.0, E=0.0, O=0.0;
    for(int i=1; i<n; i++)
    {
    	if(i%2)
    	O+=fx[i];
    	else
    	E+=fx[i];
    }
    I=((X+4*O+2*E)*h)/3;
    printf("Integral value: %lf\n", I);
    return 0;
}
