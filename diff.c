#include <stdio.h>
#include <math.h>
#define f(x) ((x*x)+1)

int main() {
    double a, b;
    int n = 10;

    a = 0.0, b = 2.0;
    double x[n+1], fx[n+1], dfx[n+1];
    double h = (b-a)/n;
    x[0] = a;

    for (int i = 1; i < n+1; i++)
        x[i] = x[i - 1] + h;

    for (int i = 0; i < n+1; i++)
        fx[i] = f(x[i]);

    for (int i = 0; i < n; i++) {
        dfx[i] = (fx[i+1]-fx[i])/h;
    }

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\ti\t\tx[i]\t\t\tf(x[i])\t\t\tf'(x[i])\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    for (int i = 0; i < n+1; i++)
        printf("\t%d\t\t%lf\t\t%lf\t\t%lf\n", i, x[i], fx[i], dfx[i]);
	
    return 0;
}
