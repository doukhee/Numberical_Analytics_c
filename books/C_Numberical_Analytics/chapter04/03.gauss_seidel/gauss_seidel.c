/**
 * 가우스 사이델 방법으로 근사 값 구하기
 */

#include <stdio.h>
#include <math.h>

/** 가우스 사이델 함수 */
void Gauss_Seidel(int matrixSize, int Max, double eps);

/** 행렬을 담을 이중 배열 변수 */
double A[50][51];
/** 결과 값을 담을 배열 선언 */
double x[50];


int main(){
    /** 행렬의 크기 및 반복 횟수 설정 */
    int matrixSize, Max;
    /** 허용 오차 및 강댁가 지배 행렬인지 확인을 위한 합 변수 선언 */
    double eps, sum;
    /** 행렬의 크기를 입력 받기 */
    printf("matrix size ? ");
    scanf("%d", &matrixSize);
    /** 행렬의 요소를 입력 받기 */
    printf("\r\nmatrix A element ? \r\n");
    /** 행렬의 행만큼 반복 */
    for(int i = 0; i < matrixSize; i++){
        /** 몇 행렬인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 행렬의 열만큼 반복 */
        for(int j = 0; j < matrixSize; j++){
            /** 행렬의 요소의 값 입력 받기 */
            scanf("%lf", &A[i][j]);
        }
    }
    /** 행렬의 값을 입력 받기 */
    printf("\r\nB element ? \r\n");
    /** 행렬의 수만큼 반복 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 값을 입력 받아서 저장 */
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
                /** 행렬의 요소를 절대값 합 구하기 */
                sum = sum + fabs(A[i][j]);
            }
        }
        /** 대각 성분의 절대값과 대각 성분 외의 절대값의 합을 비교 했을 때, 대각 성분 값이 작으면 */
        if(fabs(A[i][i]) < sum){
            /** 강대각 지배 행렬이 아닌 것을 알려주고 종료 */
            printf("\r\ninput matrix \'not Diagonally dominant matrix\'\r\n");
            return 0;
        }
    }
    /** 최대 반복 횟수 입력 받기 */
    printf("\r\nMax interval count ? ");
    scanf("%d", &Max);
    /** 허용 오차 입력 받기 */
    printf("\r\nallowable error ? ");
    scanf("%lf", &eps);
    /** 초기 값 입력 받기 */
    printf("Init vector element ? ");
    /** 행렬의 수 만큼 반복 */
    for(int i =0; i < matrixSize; i++){
        /** 초기 값 입력 받아 저장 */
        scanf("%lf", &x[i]);
    }
    /** 가우스 사이델 함수 실행 */
    Gauss_Seidel(matrixSize, Max, eps);
    return 0;
}

/** 가우스 사이델 함수 */
void Gauss_Seidel(int matrixSize, int Max, double eps){
    /** 합을 담을 임시 변수와 벡터의 크기를 담기 위한 변수 가우스 사이델으로 구한 값을 담을 행렬 변수 선언 */
    double sum, norm;
    double next_x[50] = '\0';
    /** 최대 반복 횟수만큼 반복 */
    for(int k = 1; k <=Max; k++){
        /** 반복 횟수 출력 하기 */
        printf("\r\nk = %d \r\n", k);
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 행렬 계산으로 구할 값 저장할 변수 초기화 */
            sum = 0.;
            /** 행렬의 열만큼 반복 */
            for(int j = 0; j < matrixSize; j++){
                /** 대각 성분 아래이면 */
                if(j < i){
                    /** 전의 값을 가지고 행렬 계산 */
                    sum = sum + (A[i][j] * next_x[j]);
                /** 대각 성분 아래가 아니면 */
                }else{
                    /** 위 대각 성분일경우 */
                    if(j > i){
                        /** 행렬을 계산 */
                        sum = sum + (A[i][j] * x[j]);
                    }
                }
            }
            /** 근사값 계산 */
            next_x[i] = (A[i][matrixSize] - sum) / A[i][i];
            /** 근사값을 출력 */
            printf("%lf\t", next_x[i]);
        }
        /** 한 줄 띄기 */
        printf("\r\n");
        /** 벡터의 크기를 담을 변수 초기화 */
        norm = 0.;
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 기존의 벡터의 크기가 현재 벡터의 크기보다 작을 경우 */
            if(norm < fabs(next_x[i] - x[i])){
                /** 벡터의 크기를 구하기 */
                norm = fabs(next_x[i] - x[i]);
            }
        }
        /** 허용 오차보다 벡터의 크기가 작으면 함수 종료 */
        if(norm <= eps){
            return;
        }
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < matrixSize; i++){
            /** 근사 값을 저장 */
            x[i] = next_x[i];
        }
    }
    return;
}