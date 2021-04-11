#include <stdio.h>
#include <math.h>

double A[50][51], B[50][50], x[50];

void Gauss_Jordan(int MatrixSize);
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
    double y[50], beta, eigenValue, eta, sum, back_eigenValue = 0;
    for(int k = 1; k <= Max; k++){
        printf("\r\nK = %d \r\n", k);
        for(int i = 0; i < MatrixSize; i++){
            for(int j = 0; j < MatrixSize; j++){
                A[i][j] = B[i][j];
            }
            A[i][i] = A[i][i] - alpha;
            A[i][MatrixSize] = x[i];
        }
        Gauss_Jordan(MatrixSize);
        for(int i = 0; i < MatrixSize; i++){
            y[i] = A[i][MatrixSize];
        }
        sum = 0.;
        for(int i = 0; i < MatrixSize; i++){
            sum = sum + x[i] * y[i];
        }
        beta = sum;
        sum = 0.;
        for(int i = 0; i < MatrixSize; i++){
            sum = sum + y[i] * y[i];
        }
        eta = pow(sum, 0.5);
        eigenValue = 1/ beta + alpha;
        printf("\r\n고유치는 : %lf \r\n", eigenValue);
        printf("\r\n고유벡터는 ? ");
        for(int i = 0; i < MatrixSize; i++){
            printf("%lf\t", x[i] = y[i] / eta);
        }
        if(fabs(eigenValue - back_eigenValue) < eps){
            return;
        }
        back_eigenValue = eigenValue;
    }
    return;
}

void Inverse_Powert(int MatrixSize, int Max, double alpha, double eps){
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
        Gauss_Jordan(MatrixSize);
        for(int i = 0; i < MatrixSize; i++){
            y[i] = A[i][MatrixSize];
        }
        sum = 0.;
        for(int i = 0; i < MatrixSize; i++){
            sum = sum + x[i] * y[i];
        }
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

