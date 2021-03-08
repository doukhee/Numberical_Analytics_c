#include <stdio.h>
#include <math.h>

void Jacobi(int matrixSize, int Max, double eps);

double A[50][51];
double x[50];

int main(int argc, char** argv){
    int matrixSize, Max;
    double eps, sum;
    printf("matrix A size ? ");
    scanf("%d", &matrixSize);
    printf("\r\nmatrix A element ? \r\n");
    for(int i = 0; i < matrixSize; i++){
        printf("%d row : ", i + 1);
        for(int j = 0; j < matrixSize; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    printf("\r\nb element ? \r\n");
    for(int i = 0; i < matrixSize; i++){
        scanf("%lf", &A[i][matrixSize]);
    }
    for(int i = 0; i < matrixSize; i++){
        sum = 0.;
        for(int j = 0; j < matrixSize; j++){
            if(i != j){
                sum = sum + fabs(A[i][j]);
            }
        }
        if(fabs(A[i][i]) < sum){
            printf("\r\ninput matrix \'not Diagonally dominant matrix\'\r\n");
            return 1;
        }
    }
    printf("\r\n max internal count Max ? ");
    scanf("%d", &Max);
    printf("\r\n allowable error ? ");
    scanf("%lf", &eps);
    printf("Init vector element ? ");
    for(int i = 0 ; i < matrixSize; i++){
        scanf("%lf", &x[i]);
    }
    Jacobi(matrixSize, Max, eps);
    return 0;
}

void Jacobi(int matrixSize, int Max, double eps){
    double sum, norm, next_x[50];

    for(int k = 1; k <= Max; k++){
        printf("\r\nk = %d \r\n", k);
        for(int i = 0 ; i < matrixSize; i++){
            sum = 0.;
            for(int j = 0; j < matrixSize; j++){
                if(i != j){
                    sum = sum + A[i][j] * x[j];
                }
            }
            next_x[i] = (A[i][matrixSize] - sum) / A[i][i];
            printf("%lf\t", next_x[i]);
        }
        norm = 0.;
        for(int i = 0; i < matrixSize; i++){
            if(norm < fabs(next_x[i] - x[i])){
                norm = fabs(next_x[i] - x[i]);
            }
        }
        if(norm <= eps){
            return;
        }
        for(int i = 0; i < matrixSize; i++){
            x[i] = next_x[i];
        }
    }
    printf("\r\n");
    return;
}