#include <stdio.h>
#include <math.h>
#define tol 10.e-6
double val(double x)
{
    return x*x*x + 4 * x*x - 10;
}

int main()
{
    double a = 1.25, b = 1.5, mid, f_mid;

    int iterations = 0;
	
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Iter\t\ta\t\tb\t\tc\t\tf(a)\t\tf(b)\t\tf(c)\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    while (1)
    {
        mid = (b*val(a)-a*val(b))/(val(a)-val(b));
        f_mid = val(mid);
	
        iterations++;
	printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",iterations, a,b,mid,val(a),val(b),f_mid);
        if (fabs(f_mid)<=tol)
        {
            printf("Root: %lf\n", mid);
            break;
        }
        else
        {
            a = b;
            b= mid;
        }
    }


    return 0;
}

