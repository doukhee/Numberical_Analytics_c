#include <stdio.h>
#include <math.h>

/** 벡터의 노름의 값을 구하기 위한 함수 */
void Vector_Norm(int vectorSize);
/** 벡터를 담을 배열 */
double x[50];

int main(){
    /** 벡터의 사이즈를 담기 위한 변수 */
    int vectorSize;
    /** 벡터의 사이즈를 입력 받기 */
    printf("vector x size ? ");
    scanf("%d", &vectorSize);
    /** 벡터의 요소를 입력 받기 위한 출력 */
    printf("\r\nvector element ? \r\n");
    /** 벡터의 요소를 입력 받기 위한 반복문 */
    for(int i = 0; i < vectorSize; i++){
        /** 벡터의 요소를 입력 받기 */
        scanf("%lf", &x[i]);
    }
    /** 벡터의 노름 구하기 */
    Vector_Norm(vectorSize);

    return 0;
}

/** 벡터의 노름을 구하는 함수 */
void Vector_Norm(int vectorSize){
    /** 벡터의 합 및 벡터의 최대 크기를 담기 위한 변수 */
    double vectorSum, vectorMax = 0;
    /** 벡터의 합 초기화 */
    vectorSum = 0.;
    /** 벡터의 1차 노름을 구하기 위한 반복문 */
    for(int i = 0; i < vectorSize; i++){
        /** 벡터의 요소를 절대값으로 합을 구하기 */
        vectorSum = vectorSum + fabs(x[i]);
    }
    /** 벡터의 1차 노름 구한 것을 출력 하기 */
    printf("\r\n ||x||_1 = %lf \r\n", vectorSum);
    /** 벡터의 합 초기화 */
    vectorSum = 0.;
    /** 벡터의 크기를 구하기 위한 반복문 */
    for(int i = 0 ; i <vectorSize;  i++){
        /** 벡터의 크기를 구하기 위해서 제곱의 합을 구하기 */
        vectorSum = vectorSum + pow(x[i], 2);
    }
    /** 벡터의 크기는 각 요소의 제곱의 합의 루트 값을 출력 한다 */
    printf("||x||_2 = %lf\r\n", sqrt(vectorSum));
    /** 벡터의 요소의 값 중 가장 큰 값 구하기 위한 반복문 */
    for(int i = 0; i < vectorSize; i++){
        /** 벡터의 절대값의 최대 값을 구하기 위한 if문 */
        if(fabs(x[i] >= vectorMax)){
            /** 절대값을 벡터 최대값 변수에 저장 */
            vectorMax = fabs(x[i]);
        }
    }
    /** 벡터의 요소의 절대값이 최대인 것을 출력 */
    printf("||x||_inf = %lf \r\n", vectorMax);
    return;
}