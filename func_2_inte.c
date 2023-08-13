#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) (sqrt(x))
#define g(x) ((x*x))
#define h(x) (f(x)-g(x))
#define tol 10.e-6

void simpson(double a, double h, int n)
{
    double x[n+1], fx[n+1], I, Odd=0, Ev=0, X;
    int i;
    
    x[0]=a;
    fx[0]=h(x[0]);
    
    for(i=1; i<=n; i++)
    {
    	x[i] = x[i-1]+h;
    	fx[i] = h(x[i]);
    }
    X=fx[0]+fx[n];
    for(i=1; i<n; i++)
    {
    	if(i%2)
    	Odd+=fx[i];
    	else
    	Ev+=fx[i];
    }
    I=((X+4*Odd+2*Ev)*h)/3;
    printf("Simpson's value: %lf\n", I);
}

double bisection(double a, double b)
{
    double mid, f_mid;
    if(h(a)*h(b)>0)
    {
    	printf("No root\n");
    	exit(1);
    }
    while (1)
    {
        mid = (a + b) / 2;
        f_mid = h(mid);
        if (fabs(f_mid)<=tol)
        return mid;
        else if (f_mid * h(a) < 0)
        b = mid;
        else
        a = mid;
    }
    exit(EXIT_FAILURE);

}
int main()
{
    int n=1000,i;
    double a=0.0,b=bisection(0.8, 1.2),h=(b-a)/n;
    simpson(a,h, n);
    return 0;
}
