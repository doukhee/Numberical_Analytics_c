#include <stdio.h>

/** 행을 변경하는 함수 */
void Row_change(int, int, int);
/** 행렬 선언 ㄴ*/
double A[50][50];

int main(){
    /** 행렬의 행과 열 그리고 변경할 행을 담을 변수 선언 */
    int row, column, change_row1, change_row2;
    /** 행렬의 행과 열을 입력 하라는 출력 */
    printf("matrix row column ? : ");
    /** 행렬의 행과 열을 변수에 저장 */
    scanf("%d %d", &row, &column);
    /** 행렬의 요소를 입력 받기 위한 반복문 */
    for(int i = 0; i < row; i++){
        /** 몇번째 행인지 알려주기 위한 출력 */
        printf("%d row : ", i + 1);
        /** 행의 요소 값을 열의 갯수 만큼 입력 받기 위한 반복문 */
        for(int j = 0; j < column; j++){
            /** 행렬의 요소를 입력 받기 */
            scanf("%lf", &A[i][j]);
        }
    }
    /** 변경할 행의 입력을 위한 행 2개 안내 출력 */
    printf("\r\nchange row number ? ");
    /** 변경할 행 2개 입력 받아서 저장 */
    scanf("%d %d", &change_row1, &change_row2);
    /** 행 2개 변경 진행*/
    Row_change(change_row1, change_row2, column);
    printf("\r\nresult \r\n");
    /** 결과를 출력하기 위한 행 수 만큼 반복문 */
    for(int i = 0; i < row; i++){
        /** 요소의 값을 가져오기 위한 열의 반복문 */
        for(int j = 0; j < column; j++){
            /** 요소의 값 출력 */
            printf("%lf\t", A[i][j]);
        }
        /** 한줄 완료시 한줄 띄기 */
        printf("\r\n");
    }
    return 0;
}
/** 행을 변경하기 위한 함수 */
void Row_change(int change_row1, int change_row2, int column){
    /** 요소의 값을 임시 저장하기 위한 변수 선언 */
    double changeTemp;
    /** 열의 수 만큼 반복하여 행의 요소를 변경하기 위한 반복문 */
    for(int j = 0; j < column; j++){
        /** 바꿀 행의 값을 임시로 저장하기 */
        changeTemp = A[change_row1 - 1][j];
        /** 행의 요소 변경 */
        A[change_row1 - 1][j] = A[change_row2 - 1][j];
        /** 임시 저장한 행의 요소에 저장 */
        A[change_row2 - 1][j] = changeTemp;
    }

    return;
}