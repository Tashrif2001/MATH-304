#include <stdio.h>
#include <math.h>
#define tol 10.e-6
double val(double x)
{
    return pow(x, 3) + 4 * pow(x, 2) - 5;
}

int main()
{
    double a = -5.0, b, mid, f_mid, h=10/6 ;
	b=a+h;
    int iterations = 0;
	
    while(b<=5)
    {
    if(val(a)*val(b)>0)
    {
    	a=b;
    	b+=h;
    	continue;
    }
    while (1)
    {
        mid = (a + b) / 2;
        f_mid = val(mid);

        iterations++;
	
        if (fabs(f_mid)<=tol)
        {
            printf("Root: %lf\n", mid);
            a=b;
            b+=h;
            break;
        }
        else if (f_mid * val(a) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
        
    }
    
    }


    return 0;
}

