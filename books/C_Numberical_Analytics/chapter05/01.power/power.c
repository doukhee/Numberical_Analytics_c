#include <stdio.h>
#include <math.h>

/** 행렬을 저장할 변수 */
double A[50][50];
/** */
double x[50];
/** */
void Power(int matrixSize, int Max);

int main(int argc, char **argv){
    /** 최대 반복 횟수 및 행렬의 크기를 가져오기 위한 변ㅅ */
    int Max, matrixSize;
    /** 최대 반복 횟수 입력 받기 */
    printf("Max Repeat Number ? ");
    scanf("%d", &Max);
    /** 행렬의 크기 입력 받기 */
    printf("\r\nMatrix Size ? ");
    scanf("%d", &matrixSize);
    /** 행렬의 요소 입력 받기 */
    printf("\r\nMatrix Element ? \r\n");
    /** 정행렬의 요소의 값을 입력 받기 위한 반복문 */
    for(int i = 0 ; i < matrixSize; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 행렬의 요소를 입력 받기 */
        for(int j = 0; j < matrixSize; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    /** 초기 백터 입력 받기 */
    printf("\r\nInit vector ? ");
    for(int i = 0; i < matrixSize; i++){
        scanf("%lf", &x[i]);
    }
    /** */
    Power(matrixSize, Max);
    printf("\r\n");
    return 0;
}

/** */
void Power(int matrixSize, int Max){
    /** */
    double y[50];
    /** */
    double eigenValue, eta, sum;
    /** */
    for(int k = 1; k <= Max; k++){
        /** */
        printf("\r\nk = %d \r\n", k);
        /** */
        for(int i = 0; i < matrixSize; i++){
            /** */
            sum = 0.;
            /** */
            for(int j = 0; j < matrixSize; j++){
                /** */
                sum = sum + A[i][j] * x[j];
            }
            /** */
            y[i] = sum;
        }
        /** */
        sum = 0.;
        /** */
        for(int i = 0 ; i < matrixSize; i++){
            /** */
            sum = sum + x[i] * y[i];
        }
        /** */
        printf("\t고유치는 : %lf \r\n", eigenValue = sum);
        /** */
        sum = 0.;
        /** */
        for(int i = 0; i < matrixSize; i++){
            /** */
            sum = sum + y[i] * y[i];
        }
        /** */
        eta = pow(sum, 0.5);
        /** */
        printf("\t 고유 벡터는 : ");
        /** */
        for(int i = 0; i < matrixSize; i++){
            printf("%lf \t", x[i] = y[i]/eta);
        }
    }
}