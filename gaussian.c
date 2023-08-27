#include<stdio.h>
#define NMAX 4

int main()
{
    double num[NMAX][NMAX+1] = {
   	{1, -1, 2, -1, -8}, 
    	{2,-2, 3, -3, -20}, 
    	{1, 1, 1, 0, -2}, 
    	{1, -1, 4, 3, 4}
    };
    double mij;
        
    for(int i=0; i<NMAX; i++)
    {
        for(int j=0; j<NMAX+1; j++)
       	    printf("%7.2f ", num[i][j]);
       	    printf("\n");
    }
    
    for(int i=0; i<NMAX-1; i++)
    {
    	for(int j=i+1; j<NMAX; j++)
    	{
    	    mij = num[j][i]/num[i][i];
    
    	    for(int k=i; k<NMAX+1; k++)
    	    {
    	    	num[j][k]-=mij*num[i][k];
    	    }
    	}
    	printf("Round %d: \n", i);
    for(int i=0; i<NMAX; i++)
    {
        for(int j=0; j<NMAX+1; j++)
       	    printf("%7.2f ", num[i][j]);
       	    printf("\n");
    }
    	
    }
    
    return 0;
}
