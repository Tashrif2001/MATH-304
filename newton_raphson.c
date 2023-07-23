#include <stdio.h>
#include <math.h>
#define tol 10.e-6
#define val(x) (x*x*x + 4 * x*x - 10)
#define dval(x) (3*x*x +8*x)

int main()
{
    double a = 1.25, b = 1.5, mid, f_mid;

    int iterations = 0;
    double x0=1.25;
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Iter\tx0\t\tx1\t\tf(x0)\t\tf'(x0)\t\tf(x1)\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    while (1)
    {
        double x1 = x0-(val(x0)/dval(x0));
        f_mid = val(x1);
	
        iterations++;
	printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",iterations, x0,x1,val(x0),dval(x0),val(x1));
        if (fabs(f_mid)<=tol)
        {
            printf("Root: %lf\n", x1);
            break;
        }
        else
        x0=x1;
    }


    return 0;
}

