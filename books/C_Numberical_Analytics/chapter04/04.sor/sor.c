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
    /** 허용 오차 및  완화 변수, 합을 저장하기 위한 변수 */
    double eps, freeVariable, sum;
    /** 행렬의 크기를 입력 받기 */
    printf("matrix A size ? ");
    scanf("%d", &MatrixSize);
    /** 행렬의 요소를 입력 받기 */
    for(int i = 0 ; i < MatrixSize; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 행과 열의 요소의 값 입력 */
        for(int j = 0; j < MatrixSize; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    /** 행렬의 값을 입력 받기 */
    printf("Vector b Value ? \r\n");
    /** 행렬의 수만큼 반복 */
    for(int i = 0; i < MatrixSize; i++){
        /** 행렬의 값을 입력 받기 */
        scanf("%lf", &A[i][MatrixSize]);
    }
    /** 입려고딘 행렬이 가애각 지배 행렬인지 판별 */
    /** 행렬의 행만큼 반복 */
    for(int i = 0 ; i < MatrixSize; i++){
        /** 행렬의 요소의 값을 비교 하기 위한 초기화 */
        /** 대각 성분을 제외한 값을 더하기 위한 합 변수 초기화 */
        sum = 0;
        /** 행렬의 열만큼 반복 */
        for(int j = 0; j < MatrixSize; j++){
            /** 대각 성분이 아닌 경우 */
            if(i != j){
                /** 행렬의 요소의 절대값 합 구하기 */
                sum = sum + fabs(A[i][j]);
            }
        }
        /** 대각 성분의 절대값과 대각 성분 외의 절대값의 합을 비교 했을 때, 대각 성부 값이 적으면 */
        if(fabs(A[i][i]) < sum){
            /** 강대각 지배 행렬이 아닌 것을 알려주고 종료 */
            printf("\r\ninput matrix \'not Diagonally dominant matrix\'\r\n");
            return 0;
        }
    }
    /** 최대 반복 횟수 입력 받기 */
    printf("\r\nMax Repeat Number ? ");
    scanf("%d", &Max);
    /** 허용 오차 입력 받기 */
    printf("\r\n allowable error ? ");
    scanf("%lf", &eps);
    /** 초기 백터 입력 받기 */
    printf("Init vector element ? \r\n");
    /** 행렬의 크기만큼 반복 */
    for(int i = 0; i < MatrixSize; i++){
        /** 초기 벡터의 값을 입력 받기 */
        scanf("%lf", &x[i]);
    }
    /** 완화변수를 입력 받기 */
    printf("\r\nfree variable w (0 < w < 2) ? " );
    scanf("%lf", &freeVariable);
    /** SOR 함수를 실행 */
    SOR(MatrixSize, Max, eps, freeVariable);
    return 0;
}

/** SOR 함수 */
void SOR(int MatrixSize, int Max, double eps, double freeVariable){
    /** 합과 노름 그리고, 결과 값을 저장할 배열 변수 */
    double sum, norm, next_x[50];
    /** 최대 입력 값만큼 반복 */
    for(int k = 1; k <= Max; k++){
        /** 반복 횟수를 알려주기 위한 출력 */
        printf("\r\nk = %d \r\n", k);
        /** 행렬의 최대 수 만큼 반복 */
        for(int i = 0; i < MatrixSize; i++){
            /** 행렬 계산으로 구할 값 저장할 변수 초기화 */
            sum = 0.0;
            /** 행렬의 최대 수 만큼 반복 */
            for(int j = 0; j < MatrixSize; j++){
                /** 대각 성분 아래이면 */
                if(j < i){
                    /** 전의 값을 가지고 행렬 계산 */
                    sum = sum + (A[i][j] * next_x[j]);
                /** 대각 성분 아래가 아니면 */
                }else{
                    /** 행렬 계산 */
                    sum = sum + (A[i][j] * x[j]);
                }
            }
            /** 근사 값 계산 */
            next_x[i] = x[i] - freeVariable * (sum - A[i][MatrixSize]) / A[i][i];
            /** 근 사값 출력 */
            printf("%lf\t", next_x[i]);
        }
        /** 벡터의 크기를 담을 변수 초기화 */
        norm = 0.;
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < MatrixSize; i++){
            /** 기존의 벡터의 크기가 현재 벡터의 크기보다 작을 경우 */
            if(norm < fabs(next_x[i] - x[i])){
                /** 벡터의 크기를 구하기 */
                norm = fabs(next_x[i] - x[i]);
            }
        }
        /** 허용오차보다 벡터의 크기가 적으면 함수 종료 */
        if(norm <= eps){
            return;
        }
        /** 행렬의 행만큼 반복 */
        for(int i = 0; i < MatrixSize; i++){
            /** 근사값을 저장 */
            x[i] = next_x[i];
        }
    }
    printf("\r\n");
    return;
}