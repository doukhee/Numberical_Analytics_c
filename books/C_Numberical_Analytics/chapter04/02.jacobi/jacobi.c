/**
 * 야코비 방법(Jacobi method)은 강한 대각지배행렬으로 이루어진 연립 일차 방정식에서 반복법의 수렴성을 보증하는 연립 일차 방정식 풀이법
 */

#include <stdio.h>
#include <math.h>

/** 자코비안 함수 */
void Jacobi(int matrixSize, int Max, double eps);

/** 행렬을 담을 이중 배열 */
double A[50][51];
/** 초기 값을 담기 위한 배열 */
double x[50];

int main(int argc, char** argv){
    /** 행렬의 크기와 최대 반복 횟수를 담는 인자 생성 */
    int matrixSize, Max;
    /** 오차와 합을 담을 변수 선언 */
    double eps, sum;
    /** 행렬의 크기 입력 받기 */
    printf("matrix A size ? ");
    scanf("%d", &matrixSize);
    /** 행렬의 요소 입력 받기 */
    printf("\r\nmatrix A element ? \r\n");
    /** 행렬의 행만큼 반복 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 행을 출력 */
        printf("%d row : ", i + 1);
        /** 행렬의 열만큼 반복 */
        for(int j = 0; j < matrixSize; j++){
            /** 행렬의 행과 열의 요소를 입력 받아서 저장 */
            scanf("%lf", &A[i][j]);
        }
    }
    /** 결과의 값의 요소 입력 */
    printf("\r\nb element ? \r\n");
    /** 행렬의 크기만큼 반복 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 요소 입력 받기 */
        scanf("%lf", &A[i][matrixSize]);
    }
    /** 입력된 행렬이 강대각 지배행렬인지를 판별 */
    /** 행렬의 행만큼 반복 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 요소의 값을 비교 하기 위한 초기화 */
        /** 대각 성분을 제외한 값을 더하기 위한 합 변수 초기화 */
        sum = 0.;
        /** 행렬의 열만큼 반복 */
        for(int j = 0; j < matrixSize; j++){
            /** 대각 성분이 아닐 경우 */
            if(i != j){
                /** 대각 성분 외의 값의 절대값을 더하기 */
                sum = sum + fabs(A[i][j]);
            }
        }
        /** 대각 성분의 절대값과 대각 성분 외의 절대값의 합을 비교 했을 때, 대각 성분 값이 작으면 */
        if(fabs(A[i][i]) < sum){
            /** 강대각 지배 행렬이 아닌 것을 알려주고 종료 */
            printf("\r\ninput matrix \'not Diagonally dominant matrix\'\r\n");
            return 1;
        }
    }
    /** 최대 반복 횟수 입력 받기 */
    printf("\r\n max internal count Max ? ");
    scanf("%d", &Max);
    /** 허용 오차를 입력 받기 */
    printf("\r\n allowable error ? ");
    scanf("%lf", &eps);
    /** 초기 값을 입력 받기 */
    printf("Init vector element ? ");
    /** 초기 입력 받기 위한 반복문 (행렬의 행만큼 반복) */
    for(int i = 0 ; i < matrixSize; i++){
        scanf("%lf", &x[i]);
    }
    /** 자코비안 함수 실행 */
    Jacobi(matrixSize, Max, eps);
    return 0;
}

/** 자코비안 함수 */
void Jacobi(int matrixSize, int Max, double eps){
    /** 합을 담을 임시 변수와 벡터의 크기를 담기 위한 변수 자코비안으로 구한 값을 담을 행렬 변수 선언 */
    double sum, norm, next_x[50];
    /** 최대 반복 횟수만큼 반복 */
    for(int k = 1; k <= Max; k++){
        /** 반복 횟수를 출력하기 */
        printf("\r\nk = %d \r\n", k);
        /** 행렬의 행만큼 반복 */
        for(int i = 0 ; i < matrixSize; i++){
            /** 행렬 계산으로 구할 값 초기화 */
            sum = 0.;
            /** 행렬의 열만큼 반복 */
            for(int j = 0; j < matrixSize; j++){
                /** 대각 성분이 아니면 */
                if(i != j){
                    /** 행렬 계산을 통해 값을 구하기 */
                    sum = sum + A[i][j] * x[j];
                }
            }
            /** 근사값을 구하기 (해 - 대각 성분제외한 값의 계산) / 대각 행렬 값 */
            next_x[i] = (A[i][matrixSize] - sum) / A[i][i];
            /** 자코비안으로 구한 값을 출력 */
            printf("%lf\t", next_x[i]);
        }
        /** 벡터의 크기를 초기화 */
        norm = 0.;
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /**  현재 벡터의 크기와 노름 값 비교 */
            if(norm < fabs(next_x[i] - x[i])){
                /** 벡터의 크기 구하기 */
                norm = fabs(next_x[i] - x[i]);
            }
        }
        /** 백터의 크기가 오차범위보다 작을 경우 */
        if(norm <= eps){
            /** 함수 종료 */
            return;
        }
        /** 행렬의 근사 값을 저장 */
        for(int i = 0; i < matrixSize; i++){
            /** */
            x[i] = next_x[i];
        }
    }
    printf("\r\n");
    return;
}