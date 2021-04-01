#include <stdio.h>
#include <math.h>

/** SOR로 계산하는 함수 */
void SOR(int MatrixSize, int Max, double eps, double freeVariable);
/** 입력 받을 행렬을 저장할 변수 */
double A[50][51];

/** 행렬의 초기 값 입력 받을 변수 */
double x[50];

int main(){
    /** 행렬의 크기 및 최대 반복 횟수를 저장할 변수 */
    int MatrixSize, Max;
    /** 허용 오차 및 */
    double eps, freeVariable, sum;
    printf("matrix A size ? ");
    scanf("%d", &MatrixSize);

    for(int i = 0 ; i < MatrixSize; i++){
        printf("%d row : ", i + 1);
        for(int j = 0; j < MatrixSize; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Vector b Value ? \r\n");
    for(int i = 0; i < MatrixSize; i++){
        scanf("%lf", &A[i][MatrixSize]);
    }
    for(int i = 0 ; i < MatrixSize; i++){
        sum = 0;
        for(int j = 0; j < MatrixSize; j++){
            if(i != j){
                sum = sum + fabs(A[i][j]);
            }
        }
        if(fabs(A[i][i]) < sum){
            printf("\r\ninput matrix \'not Diagonally dominant matrix\'\r\n");
            return 0;
        }
    }

    printf("\r\nMax Repeat Number ? ");
    scanf("%d", &Max);
    printf("\r\n allowable error ? ");
    scanf("%lf", &eps);
    printf("Init vector element ? \r\n");
    for(int i = 0; i < MatrixSize; i++){
        scanf("%lf", &x[i]);
    }
    printf("\r\nfree variable w (0 < w < 2) ? " );
    scanf("%lf", &freeVariable);
    SOR(MatrixSize, Max, eps, freeVariable);
    return 0;
}

void SOR(int MatrixSize, int Max, double eps, double freeVariable){
    double sum, norm, next_x[50];
    for(int k = 1; k <= Max; k++){
        printf("\r\nk = %d \r\n", k);
        for(int i = 0; i < MatrixSize; i++){
            sum = 0.0;
            for(int j = 0; j < MatrixSize; j++){
                if(j < i){
                    sum = sum + (A[i][j] * next_x[j]);
                }else{
                    sum = sum + (A[i][j] * x[j]);
                }
            }
            next_x[i] = x[i] - freeVariable * (sum - A[i][MatrixSize]) / A[i][i];
            printf("%lf\t", next_x[i]);
        }
        norm = 0.;
        for(int i = 0; i < MatrixSize; i++){
            if(norm < fabs(next_x[i] - x[i])){
                norm = fabs(next_x[i] - x[i]);
            }
        }
        if(norm <= eps){
            return;
        }
        for(int i = 0; i < MatrixSize; i++){
            x[i] = next_x[i];
        }
    }
    printf("\r\n");
    return;
}