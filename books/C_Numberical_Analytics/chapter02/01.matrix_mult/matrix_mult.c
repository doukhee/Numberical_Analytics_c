#include <stdio.h>

/**
 * 행렬의 곱셉
 * A = A11 A12 A13
 *     A21 A22 A23
 *     A31 A32 A33
 * B = B11 B12 B13
 *     B21 B22 B23
 *     B31 B32 B33
 * C = A * B
 * C = A11 * B11 + A12 * B21 + A13 * B31, A11 * B21 + A12 * B22 + A13 * B32, A11 * B31 + A12 * B32 + A13 * B33
 *     A21 * B11 + A22 * B21 + A23 * B31, A21 * B21 + A22 * B23 + A23 * B32, A21 * B31 + A22 * B32 + A23 * B33
 */


/** 행렬 곱 계산하는 함수*/
void Matrix_Mult(int, int , int);
/** 행렬 선언 */
double A[20][20], B[20][20], C[20][20];

int main(){
    /** 행렬A 행과 열, 그리고, 행렬B 열을 입력 받아서 저장하기 위한 변수 */
    int Arow, Acolumns, Bcolumns;
    /**  행렬A 행과 열, 그리고, 행렬B 열을 입력하는 것을 알려주기 위한 출력 */
    printf("Front matrix size row, columns and Back matrix columns input : ");
    /**  행렬A 행과 열, 그리고, 행렬B 열을 입력 받아서 변수에 저장 */
    scanf("%d %d %d", &Arow, &Acolumns, &Bcolumns);
    /** 행렬 A의 요소를 입력 받기 */
    printf("\r\n put in Front element : \r\n");
    /** 행렬 A의 요소를 입력 받기 */
    for(int i = 0 ; i < Arow; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 열의 요소 값을 입력 받기 위한 반복문 */
        for(int j = 0 ; j < Acolumns; j++){
            /** 행렬 A의 행과 열에 요소의 값 저장 */
            scanf("%lf", &A[i][j]);
        }
    }
    printf("\r\nput in Back matrix element : \r\n");
    /** 행렬 B의 요소를 입력 받기 */
    for(int i = 0; i < Acolumns; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 열의 요소 값을 입력 받기 위한 반복문 */
        for(int j = 0; j < Bcolumns; j++){
            /** 행렬 B의 행과 열에 요소의 값 저장 */
            scanf("%lf", &B[i][j]);
        }
    }
    /** 행렬의 곱셈 실행 */
    Matrix_Mult(Arow, Acolumns, Bcolumns);
    /** 결과 갑 출력*/
    printf("matrix multple result : \r\n");
    /** 행에 모두 접근하기 위한 반복문 */
    for(int i = 0; i < Arow; i++){
        /** 행의 열 요소에 접근 하기 위한 반복문 */
        for(int j = 0; j < Bcolumns; j++){
            /** 행렬의 요소의 값을 출력 하기 */
            printf("%lf\t", C[i][j]);
        }
        /** 한 행의 요소가 다 출력 후 한 줄 띄기 위한 출력 */
        printf("\r\n");
    }
    return 0;
}

/** 행렬의 곱셈을 하기 위한 함수 */
void Matrix_Mult(int Arow, int Acolumns, int Bcolumns){
    /** 행렬의 곱셈 결과를 담기 위한 double형의 변수 */
    double sum;
    /** 첫번째 행의 수 만큼 반복 */
    for(int i = 0; i < Arow; i++){
        for(int j = 0; j < Bcolumns; j++){
            /** 행과열의 요소의 값을 담을 변수 초기화 */
            sum = 0;
            /** 행렬의 곱셈을 진행하기 위한 반복문 */
            for(int k = 0; k < Acolumns; k++){
                /** 행렬의 곲을 실행해서 구하는 행렬의 요소의 값 */
                sum = sum + A[i][k] * B[k][j];
            }
            /** 값을 새로운 행렬에 저장 */
            C[i][j] = sum;
        }
    }
    return;
}