#include <stdio.h>

void Gauss_Jordan(int matrixSize);

double A[50][100];

int main(){
    int matrixSize;
    printf("matrix size : ");
    scanf("%d", &matrixSize);
    printf("\r\nmatrix A element? \r\n");
    for(int i = 0; i < matrixSize; i++){
        printf("%d row : ", i + 1);
        for(int j = 0; j < matrixSize; j++){
            scanf("%lf", &A[i][j]);
        }
        for(int j = matrixSize; j < 2 * matrixSize; j++){
            if(j == i + matrixSize){
                A[i][j] = 1.;
            }else{
                A[i][j] = 0;
            }
        }
    }
    Gauss_Jordan(matrixSize);
    printf("\r\nInverse matrix : \r\n");
    for(int i = 0; i < matrixSize; i++){
        for(int j = matrixSize; j <2 * matrixSize; j++){
            printf("%lf\t", A[i][j]);
        }
        printf("\r\n");
    }
    return 0;
}

void Gauss_Jordan(int matrixSize){
    double temp;
    for(int j = 0; j < matrixSize; j++){
        if(A[j][j] == 0){
            for(int i = j + 1; i < matrixSize; i++){
                if(A[i][j] != 0){
                    for(int k = j; k < matrixSize + 1; k++){
                        temp = A[j][k];
                        A[j][k] = A[i][k];
                        A[i][k] = temp;
                    }
                    break;
                }
            }
        }
        if(A[j][j] == 0){
            printf("\r\nnot regular matrix\r\n");
            return;
        }
        for(int i = j + 1; i < matrixSize; i++){
            for(int k = j + 1; k < 2 * matrixSize; k++){
                A[i][k] = A[i][k] - (A[i][j] / A[j][j]) * A[j][k];
            }
        }
    }
    for(int i = matrixSize - 1; i >= 0; i--){
        for(int k = matrixSize; k < 2 * matrixSize; k++){
            A[i][k] = A[i][k] / A[i][i];
        }
        for(int j = i - 1; j >= 0; j--){
            for(int k = matrixSize; k < 2 * matrixSize; k++){
                A[j][k] = A[j][k] - A[j][i] * A[i][k];
            }
        }
    }
    return;
}