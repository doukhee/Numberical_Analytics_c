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

/** 거듭제곱 방법으로 방정식 푸는 함수 */
void Power(int matrixSize, int Max){
    /** 결과를 저장 하기 위한 변수 선언 */
    double y[50];
    /** 고유치, 고유값, 행렬 계산의 값을 저장하기 위한 합 변수 선언 */
    double eigenValue, eta, sum;
    /** y = A[(k-1)] 계산 */
    /** 최대 횟수만큼 반복 하기 위한 반복문 */
    for(int k = 1; k <= Max; k++){
        /** 몇번째 실행인지 알려주기 위한 출력 */
        printf("\r\nk = %d \r\n", k);
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 합변수를 0.으로 초기화 */
            sum = 0.;
            /** 행렬의 열만큼 반복 */
            for(int j = 0; j < matrixSize; j++){
                /** 행렬의 곱의 값을 저장 */
                sum = sum + A[i][j] * x[j];
            }
            /** 행렬의 곱 계산 값을 임시 저장 */
            y[i] = sum;
        }
        /** 합변수를 0.으로 초기화 */
        sum = 0.;
        /** 행렬읠 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 초기 값과 행렬의 곱 계산의 내적 값 구히기 */
            sum = sum + x[i] * y[i];
        }
        /** 고유치를 출력 하기 */
        printf("\t고유치는 : %lf \r\n", eigenValue = sum);
        /** 행렬의 고유 벡터를 구하기 위한 합 변수 초기화 */
        sum = 0.;
        /** 행렬의 크기만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 행렬의 곱의 제곱 노름값 구하기 */
            sum = sum + y[i] * y[i];
        }
        /** 노름값의 루트 값을 저장 */
        eta = pow(sum, 0.5);
        /** 고유벡터 출력을 알려주기 위한 출력 */
        printf("\t 고유 벡터는 : ");
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 행렬의 고유 벡터 출력 */
            printf("%lf \t", x[i] = y[i]/eta);
        }
    }
}