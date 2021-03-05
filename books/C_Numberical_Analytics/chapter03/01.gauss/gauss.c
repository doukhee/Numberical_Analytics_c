#include <stdio.h>

/** 가우스 소거법 함수 */
void gauss(int matrixSize);
/** 행렬 선언 정행렬이지만, 열이 추가된 것은 덧붙임 행렬을 하기 위해서 이다 */
double A[50][51];

void showMatrix(double (*matrix)[51], int msize);

int main(){
    /** 입력 받을 행렬의 크기를 담을 변수 */
    int matrixSize;
    /** 행렬의 크기 입력 받기 */
    printf("A matrix size ? ");
    scanf("%d", &matrixSize);
    /** 행렬의 요소를 입력 받기 */
    printf("\r\nmatrix element ?\r\n");
    /** 행렬의 행만큼 반복 하기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 행렬의 열만큼 반복 하기 위한 반복문 */
        for(int j = 0; j < matrixSize; j++){
            /** 행렬의 요소 입력 받아서 행렬에 저장 */
            scanf("%lf", &A[i][j]);
        }
    }
    /** 행렬의 값을 입력 받기 */
    printf("b element ? \r\n");
    /** 행렬의 값을 저장하기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 값 저장 */
        scanf("%lf", &A[i][matrixSize]);
    }
    /** 가우스 소거법 실행 */
    gauss(matrixSize);

    return 0;
}

/** 가우스 소거법 함수 */
void gauss(int matrixSize){
    /** 임시로 값을 저장할 변수 선언 */
    double temp;
    /** 위삼각행렬화를 위한 반복문 */
    for(int j = 0; j <matrixSize; j++){
        /** 행과 열의 값이 같은 요소의 값이 0이면 */
        if(A[j][j] == 0){
            /** 부분피벗을 위한 반복문 */
            /** 대각 성분의 다음 열의 값을 비교하기 위한 반복문 */
            for(int i = j + 1; i < matrixSize; i++){
                /** 부분피벗 가우스 소거법 */
                /** 대각성분 다음 열이 0이 아니면 */
                if(A[i][j] != 0){
                    /** 행을 변경해주기 위한 반복문 */
                    for(int k = j; k < matrixSize + 1; k++){
                        /** 행렬의 행을 변경하기 위한 임시 저장 */
                        temp = A[j][k];
                        /** 행렬의 행의 전 행과 값을 변경 */
                        A[j][k] = A[i][k];
                        /** 행렬의 행의 전행과 지금 행의 값 변경 */
                        A[i][k] = A[j][k];
                    }
                    /** 대각 성분 다음열 비교하기 위한 반복문 탈출 */
                    break;
                }
            }
        }
        /** 대각 성분에 0이 있으면 중단하기 위한 조건문 */
        if(A[j][j] == 0){
            /** 정칙행렬이 아닌 것을 알려주기 위한 출력 */
            printf("not regular matrix\r\n");
            /** 함수 종료 */
            return;
        }
        /** 위삼각행렬 공식 */
        /** 위삼각행렬을 만들기 위한 반복문 */
        for(int i = j + 1; i < matrixSize; i++){
            /** */
            A[i][j] = -A[i][j]/A[j][j];
            /** */
            for(int k = j + 1; k < matrixSize + 1; k++){
                /** */
                A[i][k] = A[i][k] + A[i][j] * A[j][k];
            }
        }
    }
    /** 역대입법 공식 */
    /** 역대입법을 이용한 값을 구하기 위한 반복문 */
    for(int i = matrixSize - 1; i >= 0; i--){
        /** */
        for(int k = i + 1; k < matrixSize; k++){
            /** */
            A[i][matrixSize] = A[i][matrixSize] - A[i][k] * A[k][matrixSize];
        }
        /** */
        A[i][matrixSize] = A[i][matrixSize] / A[i][i];
    }
    /** 결과값을 알려주기 위한 출력 */
    printf("\r\nresult x value : \r\n");
    /** 구한 값을 출력하기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 가우스 소거법을 이용해서 구한 값을 출력 */
        printf("%lf\t", A[i][matrixSize]);
    }
    /** 출력 시 값을 보기 편하게 하기 위한 한 줄 띄기 */
    printf("\r\n");
    return;
}