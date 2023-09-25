#include<stdio.h>
#define N 3

void printMat(double mat[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%0.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void multiply(double mat1[N][N], double mat2[N][N])
{
    double res[N][N];
    for(int k=0; k<3; k++)
    {
    	for(int j=0; j<3; j++)
    	{
    	    for(int i=0; i<3; i++)
    	    res[i][j] += mat1[i][k]*mat2[k][j];
    	}
    }
    printMat(res);
}
void gaussianSol(double L[N][N], double U[N][N], double B[N][1])
{
    double Laug[N][N+1], Yaug[N][N+1];
    //Laug
    for(int i=0; i<N; i++)
    {
    	for(int j=0 ;j<N+1; j++)
    	{
    	    if(j==N)
    	    Laug[i][j]= B[i][0];
    	    else
    	    Laug[i][j] = L[i][j];
    	}
    }
    printf("Laug\n");
    for(int i=0; i<N; i++)
    {
    	for(int j=0 ;j<N+1; j++)
    	{
    	    printf("%0.2f ", Laug[i][j]);
    	}
    	printf("\n");
    }
    //gaussian_reduction
    for(int i=0; i<N-1; i++)
    {
    	for(int j=i+1; j<N; j++){
    	    double ratio = Laug[j][i]/Laug[i][i];
    	    for(int k=0; k<N+1; k++)
    	    Laug[j][k] -= ratio*Laug[i][k];
    	}
    }
    //backward
    for(int i=N-1; i>=0; i--)
    {
    	for(int j=i-1; j>=0; j--){
    	    double ratio = Laug[j][i]/Laug[i][i];
    	    for(int k=0; k<N+1; k++)
    	    Laug[j][k] -= ratio*Laug[i][k];
    	}
    }
    //diagonal factor
    int k=0;
    for(int i=0; i<N; i++)
    {
    	double fact = Laug[k][k];
    	for(int j=0; j<N+1; j++)
    	Laug[i][j]/=fact;
    	k++;
    }
    //solve&&Yaug
    double Y[N][1];
    for(int i=0; i<N; i++)
    {
    	//printf("%0.2f ", Laug[i][N]);
    	Y[i][0] = Laug[i][N];
    }
    //Yaug
    for(int i=0; i<N; i++)
    {
    	for(int j=0 ;j<N+1; j++)
    	{
    	    if(j==N)
    	    Yaug[i][j]= Y[i][0];
    	    else
    	    Yaug[i][j] = U[i][j];
    	}
    }
    //printYaug
    printf("Yaug\n");
    for(int i=0; i<N; i++)
    {
    	for(int j=0 ;j<N+1; j++)
    	{
    	    printf("%0.2f ", Yaug[i][j]);
    	}
    	printf("\n");
    }
    
    //gauss
    for(int i=0; i<N-1; i++)
    {
    	for(int j=i+1; j<N; j++){
    	    double ratio = Yaug[j][i]/Yaug[i][i];
    	    for(int k=0; k<N+1; k++)
    	    Yaug[j][k] -= ratio*Yaug[i][k];
    	}
    }
    //backward
    for(int i=N-1; i>=0; i--)
    {
    	for(int j=i-1; j>=0; j--){
    	    double ratio = Yaug[j][i]/Yaug[i][i];
    	    for(int k=0; k<N+1; k++)
    	    Yaug[j][k] -= ratio*Yaug[i][k];
    	}
    }
    //diagonal factor
    k=0;
    for(int i=0; i<N; i++)
    {
    	double fact = Yaug[k][k];
    	for(int j=0; j<N+1; j++)
    	Yaug[i][j]/=fact;
    	k++;
    }
    //printSol
    printf("Solve:\n");
    for(int i=0; i<N; i++)
    {
    	printf("%0.2f ", Yaug[i][N]);
    }
    printf("\n");
}
void LU(double mat[N][N], double B[N][1])
{
    double L[N][N], U[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==j)
            L[i][j] = 1;
            else
            L[i][j] = 0;
            U[i][j] = mat[i][j];
        }
    }	
    
    //factorization
    for(int i=0; i<N; i++)
    {
    	for(int j=i+1; j<N; j++)
    	{
    	    double ratio = U[j][i]/U[i][i];
    	    L[j][i] = ratio;
    	    for(int k=0; k<N; k++)
    	    U[j][k] -= ratio*U[i][k]; 
    	}
    }
    printf("L:\n");
    printMat(L);
    printf("U:\n");
    printMat(U);
    printf("A=LxU:\n");
    multiply(L, U);
    gaussianSol(L,U,B);
}

int main()
{
    double mat[N][N] = {{4, 1, 1},
    			{2, 5, 2},
    			{1, 2, 4}};
    double B[N][1] = {{8},
                      {3},
                      {11}};
                      
    printf("Originally A:\n");
    printMat(mat);
    LU(mat,B);
    
    return 0;
}
