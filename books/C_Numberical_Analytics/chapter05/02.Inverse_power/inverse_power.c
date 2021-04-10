#include <stdio.h>
#include <math.h>

double A[50][51], B[50][50], x[50];

void gauss(int MatrixSize);
void Inverse_Power(int MatrixSize, int Max, double alpha, double eps);

int main(int argc, char** argv){
    int Max, MatrixSize;
    double alpha, eps;
    printf("최대 반복 횟수는 ? ");
    scanf("%d", &Max);
    printf("\r\n이동변수는 ? ");
    scanf("%lf", &alpha);
    printf("\r\n허용오차는 ? ");
    scanf("%lf", &eps);
    printf("\r\n행렬의 크기는 ? ");
    scanf("%d", &MatrixSize);
    printf("\r\n행렬의 성분은 ? \r\n");
    for(int i = 0; i < MatrixSize; i++){
        printf("%d행 : ", i + 1);
        for(int j = 0; j < MatrixSize; j++){
            scanf("%lf", &A[i][j]);
            B[i][j] = A[i][j];
        }
    }
    printf("\r\n초기벡터의 성분은 ? \r\n");
    for(int i = 0; i < MatrixSize; i++){
        scanf("%lf", &x[i]);
    }
    Inverse_Power(MatrixSize, Max, alpha, eps);
    printf("\r\n");
    return 0;
}



void Inverse_Power(int MatrixSize, int Max, double alpha, double eps){
    double y[50], beta, eta, sum, back_eigenValue = 0.;
    for(int k = 1; k <=Max; k++){
        printf("\r\nk = %d \r\n", k);
        for(int i = 0; i < MatrixSize; i++){
            for(int j = 0 ; j < MatrixSize; j++){
                A[i][j] = B[i][j];
            }
            A[i][i] = A[i][i] - alpha;
            A[i][MatrixSize] = x[i];
        }
        gauss(MatrixSize);
        for(int i = 0; i < MatrixSize; i++){
            y[i] = A[i][MatrixSize];
        }
        sum = 0.;
        for(int i = 0; i < MatrixSize; i++){
            sum = sum + x[i] * y[i];
        }
        beta =
        eta = pow(sum, 0.5);
        printf("\r\n고유 벡터는 ?");
        for(int i = 0; i < MatrixSize; i++){
            printf("%lf\t", x[i] = y[i] / eta);
        }
        for(int i = 0; i < MatrixSize; i++){
            sum = 0.;
            for(int j = 0; j < MatrixSize; j++){
                sum = sum + A[i][i] * x[j];
            }
            y[i] = sum;
        }
        sum = 0.;
        for(int i = 0; i < MatrixSize; i++){
            sum = sum + x[i] * y[i];
        }
        beta = sum;
        printf("\r\n고유치는 %lf \r\n", beta);
        if(fabs(beta - back_eigenValue) < eps){
            return;
        }
        back_eigenValue = beta;
    }
    return;
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
            /** 대각 성분 전의 값을 0으로 만들기 위한 값 만들기 */
            A[i][j] = -A[i][j]/A[j][j];
            /** 대각 성분 전의 값을 0으로 만들고 다음 열의 값을 구하기 위한 반복문 */
            for(int k = j + 1; k < matrixSize + 1; k++){
                /** 대각 성분 전의 값을 0으로 만들고 다음 열의 값을 구하기 */
                A[i][k] = A[i][k] + A[i][j] * A[j][k];
            }
        }
    }
    /** 역대입법 공식 */
    /** 역대입법을 이용한 값을 구하기 위한 반복문 */
    for(int i = matrixSize - 1; i >= 0; i--){
        /** 역대입법을 위한 반복문 */
        for(int k = i + 1; k < matrixSize; k++){
            /** 역대입으로 하나씩 행렬의 요소에 특정 값 뺴주기 */
            A[i][matrixSize] = A[i][matrixSize] - A[i][k] * A[k][matrixSize];
        }
        /** 역대입으로 구하고자 하는 값의 곱셈 되어 있는 값을 나눠주기 */
        /** 8x = y == x = y/8 */
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