#include <stdio.h>
#include <math.h>

/**
 * https://ko.wikipedia.org/wiki/%EC%88%84%EB%A0%88%EC%8A%A4%ED%82%A4_%EB%B6%84%ED%95%B4
 */

/** 숄레스키 방법을 이용한 값 구히기 위한 함수 */
void cholesky(int matrixSize);
/** 행렬을 담기 위한 이중 배열 선언 */
double A[50][50] = '\0';

int main(){
    /** 행렬의 크기 입력 받아 담기 위한 변수 선언 */
    int matrixSize;
    /** 행렬의 크기를 입력 받기 */
    printf("matrix size : ");
    scanf("%d", &matrixSize);
    /** 숄레스키 방법을 사용하기 위해서 입력 행렬이 대칭 행렬이어야 하기 때문에 대각성분 아래만 입력 받는다 */
    printf("\r\nmatrix A under element ? \r\n");
    for(int i = 0; i < matrixSize; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 대각 성분 아래 부분만 입력 받기 위한 반복문 */
        for(int j = 0; j <= i; j++){
            /** 행렬의 요소의 값 입력 받아서 저장 */
            scanf("%lf", &A[i][j]);
        }
    }
    /** 덧붙임 행렬로 행렬의 값을 입력 받기 위한 안내 출력 */
    printf("\r\nVector b element ? \r\n");
    /** 행렬의 값을 입력 받기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 값 입력 받기 */
        scanf("%lf", &A[i][matrixSize]);
    }
    /** 숄레스키 함수 실행 */
    cholesky(matrixSize);
    /** 결과 값 출력 */
    printf("\r\n value x : \r\n");
    /** 결과 값 출력을 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 결과 값 출력 */
        printf("%lf\t", A[i][matrixSize]);
    }
    printf("\r\n");
    return 0;
}
/** 숄레스키 방법 함수 */
void cholesky(int matrixSize){
    /** 아래삼각행렬의 요소의 값을 구하기 위한 변수 */
    double sum;
    /** 아래삼각행렬의 요소를 구하기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** */
        for(int j = 0; j <=i; j++){
            /** 아래삼각행렬의 요소의 값을 구하기 위한 변수 */
            sum = 0.0;
            /** 시그마 계산을 위한 반복문 */
            for(int k = 0; k <= j-1; k++){
                /** 아래삼각행렬의 값을 가지고 원 행렬에 빼줄 시그마 계산 */
                sum = sum + A[i][k] * A[j][k];
            }
            /** 대각 성분이 아닐 경우의 값 구하기 */
            if(j < i){
                /** 아래삼각행렬의 요수 값 구하기 */
                A[i][j] = (A[i][j] - sum) / A[j][j];
            /** 대각성분일 경우 */
            }else{
                /** 입력한 행렬이 양의 부호인지 확인하는 확인 if문 */
                if(A[i][i] - sum <= 0){
                    /** 입력한 행렬이 양의 정부호인 대칭행렬이 아니라는 것을 알려주기 위한 출력 */
                    printf("\r\ninput matrix not positive element\r\n");
                    /** 함수 종료 */
                    return;
                }
                /** 아래삼각행렬의 요수 값 구하기 */
                A[i][i] = pow(A[i][i] - sum, 0.5);
            }
        }
    }
    /** 아래 삼각행렬(대각성분 윗 부분의 값이 0인 행렬)을 출력을 알려주기 위한 출력 */
    printf("\r\nlower triangle matrix L : \r\n");;
    /** 행렬의 값을 출력하기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 값을 출력하기 위한 반복문 */
        for(int j = 0; j < matrixSize; j++){
            /** 행렬의 요소를 출력 */
            printf("%lf\t", A[i][j]);
        }
        /** 행을 구분하기 위한 출력 */
        printf("\r\n");
    }

    /** 대입법을 위한 반복문 */
    /** Ly = b */
    for(int j = 0; j <= matrixSize - 1; j++){
        /** 대입법으로 행렬 계산을 위한 반복문(행렬 계산) */
        for(int k = 0; k < j; k++){
            /** 계산을 하여 b의 값을 찾기 */
            A[j][matrixSize] = A[j][matrixSize] - A[j][k] * A[k][matrixSize];
        }
        /** 첫번쨰 요소의 값을 찾기 위한 계산 */
        A[j][matrixSize] = A[j][matrixSize] / A[j][j];
    }
    /** 역대입법을 위한 반복문 */
    /** y = L^t * x */
    for(int i = matrixSize - 1; i >= 0; i--){
        /** 미지수의 값 찾기 위한 반복문 */
        for(int k = i + 1; k < matrixSize; k++ ){
            /** x의 값을 찾기 위한 행렬 계산 */
            A[i][matrixSize] = A[i][matrixSize] - A[k][i] * A[k][matrixSize];
        }
        /** 첫번쨰 요소의 값을 찾기 위한 계산 */
        A[i][matrixSize] = A[i][matrixSize] / A[i][i];
    }
    return;
}