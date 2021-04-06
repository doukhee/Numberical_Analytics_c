#include <stdio.h>
#include <math.h>

double A[50][50];
double x[50];

void Power(int matrixSize, int Max);

int main(int argc, char **argv){
    int Max, matrixSize;
    printf("Max Repeat Number ? ");
    scanf("%d", &Max);
    printf("\r\nMatrix Size ? ");
    scanf("%d", &matrixSize);
    printf("\r\nMatrix Element ? \r\n");
    for(int i = 0 ; i < matrixSize; i++){
        printf("%d row : ", i + 1);
        for(int j = 0; j < matrixSize; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    printf("\r\nInit vector ? ");
    for(int i = 0; i < matrixSize; i++){
        scanf("%lf", &x[i]);
    }
    Power(matrixSize, Max);
    printf("\r\n");
    return 0;
}

void Power(int matrixSize, int Max){
    double y[50];
    double eigenValue, eta, sum;
    for(int k = 1; k <= Max; k++){
        printf("\r\nk = %d \r\n", k);
        for(int i = 0; i < matrixSize; i++){
            sum = 0.;
            for(int j = 0; j < matrixSize; j++){
                sum = sum + A[i][j] * x[j];
            }
            y[i] = sum;
        }
        sum = 0.;
        for(int i = 0 ; i < matrixSize; i++){
            sum = sum + x[i] * y[i];
        }
        printf("\t고유치는 : %lf \r\n", eigenValue = sum);
        sum = 0.;
        for(int i = 0; i < matrixSize; i++){
            sum = sum + y[i] * y[i];
        }
        eta = pow(sum, 0.5);
        printf("\t 고유 벡터는 : ");
        for(int i = 0; i < matrixSize; i++){
            printf("%lf \t", x[i] = y[i]/eta);
        }
    }
}