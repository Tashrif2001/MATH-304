#include <stdio.h>
#include<math.h>
#define R 3
#define tol 10.e-3

int check(double mat[R][R]) {
    double sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            if (i != j)
                sum += mat[i][j];
        }
        if (mat[i][i] <= sum) {
            return 0;
        }
        sum = 0;
    }
    return 1;
}

void jacob(double mat[R][R], double B[R][1]) {
    double diag[R][R], diagInv[R][R];
    double x0[R][1] = {{0}, {0}, {0}}, x1[R][1];
    // Taking diag
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            if (i == j) {
                diag[i][j] = mat[i][j];
                diagInv[i][j] = 1 / diag[i][j];
            } else {
                diag[i][j] = 0;
                diagInv[i][j] = 0;
            }
        }
    }

    
    int iter = 1; 
    while (1) {
    	double tempSum[R][1] = {0,0,0};
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < R; j++) {
                if (i != j)
                    tempSum[i][0] += (mat[i][j] * x0[j][0]);
            }
        }
	
        for (int i = 0; i < R; i++)
            tempSum[i][0] = B[i][0] - tempSum[i][0];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < R; j++) {
                x1[i][0] = tempSum[i][0] * diagInv[i][i];
            }
          
        }

        int count = 0;
        for (int i = 0; i < R; i++) {
            if (fabs(x1[i][0] - x0[i][0]) < tol)
                count++;
        }
        if (count == 3)
            break;

        printf("Iter %d: \n", iter);

        for (int i = 0; i < R; i++) {
            x0[i][0] = x1[i][0];
            printf("%lf ", x0[i][0]);
        }
        iter++;
    }
}

int main() {
    double mat[R][R] = {{4, 1, 1},
                        {2, 5, 2},
                        {1, 2, 4}};
    double B[R][1] = {{8}, {3}, {11}};

    if (check(mat)) {
        jacob(mat, B);
    }
    return 0;
}
