#include <stdio.h>

/** 가우스 조르단 함수 */
void Gauss_Jordan(int matrixSize);

/** 행렬 선언 열이 두배인 이유는 덧붙임 행렬로 역행렬 값을 저장하기 위해서 이다 */
double A[50][100];

int main(){
    /** 행렬의 크기를 입력 받기 위한 변수 선언 */
    int matrixSize;
    /** 행렬의 크기를 입력 받기 */
    printf("matrix size : ");
    scanf("%d", &matrixSize);
    /** 행렬의 요소를 입력 받기 */
    printf("\r\nmatrix A element? \r\n");
    /** 행렬의 행만큼 반복 */
    for(int i = 0; i < matrixSize; i++){
        /** 행렬의 행을 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 행렬의 열만큼 반복 */
        for(int j = 0; j < matrixSize; j++){
            /** 행렬의 요소 값 입력 받아서 행렬에 저장 */
            scanf("%lf", &A[i][j]);
        }
        /** 행렬 A의 단위 행렬을 만들기 위한 반복문 */
        for(int j = matrixSize; j < 2 * matrixSize; j++){
            /** 단위행렬은 대각 성분이 1이므로 대각 성분의 값을 1로 만들어서 값을 저장 */
            if(j == i + matrixSize){
                A[i][j] = 1.;
            /** 대각 성분 아니면, 행렬의요소의 값은 0이므로 행렬의 값을 0으로 만들어준다 */
            }else{
                A[i][j] = 0;
            }
        }
    }
    /** 가우스 조르단 함수 호출 하여 역행렬 구하기 */
    Gauss_Jordan(matrixSize);
    /** 역행렬 출력을 알려주는 출력 */
    printf("\r\nInverse matrix : \r\n");
    /** 역행렬의 행만큼 반복하기 위한 반복문 */
    for(int i = 0; i < matrixSize; i++){
        /** 역행렬의 열의 수 만큼 반복하기 위한 반복문 */
        for(int j = matrixSize; j <2 * matrixSize; j++){
            /** 행렬의 요소 값 출력 */
            printf("%lf\t", A[i][j]);
        }
        /** 행을 구분하기 위한 한줄 띄기 */
        printf("\r\n");
    }
    return 0;
}

/** 가우스 조르단 */
void Gauss_Jordan(int matrixSize){
    /** 임시저장을 위한 변수 선언 */
    double temp;
    /** 행렬의 행만큼 반복하는 반복문 */
    for(int j = 0; j < matrixSize; j++){
        /** 행렬의 대각성분이 0이면 */
        if(A[j][j] == 0){
            /** 행렬의 현재의 다음 행부터 행렬의 행만큼 반복 */
            for(int i = j + 1; i < matrixSize; i++){
                /** 다음행의 열의 값이 0이 아닐경우 */
                if(A[i][j] != 0){
                    /** 행을 변경을 해주기 위한 반복문 */
                    for(int k = j; k < matrixSize + 1; k++){
                        /** 행을 변경하기 위해서 변경을 할 행의 값을 임시 저장 */
                        temp = A[j][k];
                        /** 변경을 할 행에 교환 */
                        A[j][k] = A[i][k];
                        /** 변경을 진행한 행의 값을 교환 */
                        A[i][k] = temp;
                    }
                    /** 행을 교환하는 반복문 탈출 */
                    break;
                }
            }
        }
        /** 행렬의 대각 성분의 값이 0일 경우 */
        if(A[j][j] == 0){
            /** 정칙행렬이 아니라는 것을 알려주기 위한 출력 */
            printf("\r\nnot regular matrix\r\n");
            /** 함수 종료 */
            return;
        }
        /** 위삼각행렬화를 위해 가우스 소거법 적용 */
        /** 대각 성분 아래 값을 0으로 만들기 위한 반복문 */
        for(int i = j + 1; i < matrixSize; i++){
            /** 대각 성분 아래 부분을 0으로 만들기 위한 반복문 */
            for(int k = j + 1; k < 2 * matrixSize; k++){
                /** 대각 성분 아래 값을 0으로 만듣기 위한 계산 */
                A[i][k] = A[i][k] - (A[i][j] / A[j][j]) * A[j][k];
            }
        }
    }

    /** 항등행렬화 */
    /** 행렬을 단위 행렬로 만들기 위한 반복문 */
    for(int i = matrixSize - 1; i >= 0; i--){
        /** 역행렬을 구하기 위한 반복문 */
        for(int k = matrixSize; k < 2 * matrixSize; k++){
            /** 대각 성분의 값을 1로 만들고, 역행렬 계산 */
            A[i][k] = A[i][k] / A[i][i];
        }
        /** 대각 성분만 남기기 위한 반복문 */
        for(int j = i - 1; j >= 0; j--){
            /** 대각 성분만 남기기 위한 반복문 */
            for(int k = matrixSize; k < 2 * matrixSize; k++){
                /** 대각 성분 외의 값을 제거하기 위한 계산 */
                A[j][k] = A[j][k] - A[j][i] * A[i][k];
            }
        }
    }
    return;
}