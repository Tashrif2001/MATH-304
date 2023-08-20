#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    clock_t s,e;
    int i,j,k,num1[3][3],num2[3][3],res[3][3];
    srand(time(NULL));
    
    for(i=0; i<3; i++)
    {
    	for(j=0; j<3; j++){
    	num1[i][j]=(int)(rand()%10);
    	num2[i][j]=(int)(rand()%10);
    	res[i][j]=0;
    	}
    }
    s=clock();
    for(k=0; k<3; k++)
    {
    	for(j=0; j<3; j++)
    	{
    	    for(i=0; i<3; i++)
    	    res[i][j] += num1[i][k]*num2[k][j];
    	}
    }
    e=clock();
    printf("Matrix 1: \n");
    for(i=0; i<3; i++)
    {
    	for(j=0; j<3; j++){
    	printf("%d  ", num1[i][j]);
    	}
    	printf("\n");
    }
    
    printf("Matrix 2: \n");
    for(i=0; i<3; i++)
    {
    	for(j=0; j<3; j++){
    	printf("%d  ", num2[i][j]);
    	}
    	printf("\n");
    }
    
    printf("Resultant Matrix: \n");
    for(i=0; i<3; i++)
    {
    	for(j=0; j<3; j++){
    	printf("%d  ", res[i][j]);
    	}
    	printf("\n");
    }
    printf("%lf\n", (double)(e-s)/CLOCKS_PER_SEC);
}
