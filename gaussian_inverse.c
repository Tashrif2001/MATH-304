#include <stdio.h>

#define N 3

void printInv(double mat[N][2 * N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N; j < 2 * N; j++)
        {
            printf("%0.2f ", mat[i][j]);
        }
        printf("\n");
    }
}
double det(double inv[N][2 * N])
{
    double prod = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
            if (i == j)
                prod *= inv[i][j];
    }
    return prod;
}
void gaussianElimination(double inv[N][2 * N], double mat[N][N + 1])
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double ratio = inv[j][i] / inv[i][i];
            double ratio2 = mat[j][i] / mat[i][i];
            for (int k = 0; k < 2 * N; k++)
            {
                inv[j][k] -= ratio * inv[i][k];
            }
            for (int k = 0; k < N + 1; k++)
            {
                mat[j][k] -= ratio2 * mat[i][k];
            }
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            double ratio = inv[j][i] / inv[i][i];
            double ratio2 = mat[j][i] / mat[i][i];
            for (int k = 0; k < 2 * N; k++)
            {
                inv[j][k] -= ratio * inv[i][k];
            }
            for (int k = 0; k < N + 1; k++)
            {
                mat[j][k] -= ratio2 * mat[i][k];
            }
        }
    }

    printf("Determinant: %0.2f\n", det(inv));
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        double fact = inv[k][k];
        for (int j = 0; j < 2 * N; j++)
            inv[i][j] /= fact;
        for (int j = 0; j < N + 1; j++)
            mat[i][j] /= fact;
        k++;
    }
    printf("Mat:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%0.2f ", mat[i][N]);
    }
}

int main()
{
    double mat[N][N + 1] = {{4, 1, 1, 8},
                            {2, 5, 2, 3},
                            {1, 2, 4, 11}};
    double inv[N][2 * N] = {{4, 1, 1, 1, 0, 0},
                            {2, 5, 2, 0, 1, 0},
                            {1, 2, 4, 0, 0, 1}};

    gaussianElimination(inv, mat);

    printf("\nInverse Matrix:\n");
    printInv(inv);
    return 0;
}
