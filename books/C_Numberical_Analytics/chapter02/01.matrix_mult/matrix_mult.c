#include <stdio.h>

/** 행렬 곱 계산하는 함수*/
void Matrix_Mult(int, int , int);
/** 행렬 선언 */
double A[20][20], B[20][20], C[20][20];

int main(){

    int Arow, Acolumns, Bcolumns;

    printf("Front matrix size row, columns and Back matrix columns input : ");
    scanf("%d %d %d", &Arow, &Acolumns, &Bcolumns);
    printf("\r\n put in Front element : \r\n");
    for(int i = 0 ; i < Arow; i++){
        printf("%d row : ", i + 1);
        for(int j = 0 ; j < Acolumns; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    printf("\r\nput in Back matrix element : \r\n");
    for(int i = 0; i < Acolumns; i++){
        printf("%d row : ", i + 1);
        for(int j = 0; j < Bcolumns; j++){
            scanf("%lf", &B[i][j]);
        }
    }
    Matrix_Mult(Arow, Acolumns, Bcolumns);
    printf("matrix multple result : \r\n");
    for(int i = 0; i < Arow; i++){
        for(int j = 0; j < Bcolumns; j++){
            printf("%lf\t", C[i][j]);
        }
        printf("\r\n");
    }
    return 0;
}

void Matrix_Mult(int Arow, int Acolumns, int Bcolumns){
    double sum;
    for(int i = 0; i < Arow; i++){
        for(int j = 0; j < Bcolumns; j++){
            sum = 0;
            for(int k = 0; k < Acolumns; k++){
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return;
}