#include <stdio.h>

/** 벡터의 내적을 구하는 함수 */
double Inner_product(int );

/** 유클리드 공간을 담을 배열 변수 */
double x[30], y[30];

int main(){
    /** 벡터의 차원을 담을 변수 */
    int vectorSize;
    /** 벡터의 크기 및 차수를 입력을 알리는 출력 */
    printf("Vector size(or power)? ");
    /** 벡터의 크기를 입력 받기 */
    scanf("%d", &vectorSize);
    /** 벡터의 요소를 입력 받는 것을 알려주기 위한 출력 */
    printf("\r\nVector X element ? \r\n");
    /** 벡터의 요소를 입력 받기 위한 반복문 */
    for(int i = 0; i < vectorSize; i++){
        /** 벡터의 요소를 입력 받기 */
        scanf("%lf", &x[i]);
    }
    /** 벡터의 요소를 입력 받는 것을 알려주기 위한 출력 */
    printf("\r\nVector y element ? \r\n");
    /** 벡터의 요소를 입력 받기 위한 반복문 */
    for(int i = 0; i < vectorSize; i++){
        /** 벡터의 요소를 입력 받기 */
        scanf("%lf", &y[i]);
    }
    /** 벡터의 내적 값 출력 */
    printf("\r\n<x, y>=%lf\r\n", Inner_product(vectorSize));
    return 0;
}
/** 벡터의 내적을 구하는 함수 */
double Inner_product(int vectorSize){
    /** 내적 합을 담을 변수 */
    double sum = 0;
    /** 내적을 구하기 위한 반복문 */
    for(int i = 0; i < vectorSize; i++){
        /** 벡터의 내적 계산 */
        sum = sum + x[i] * y[i];
    }
    /** 내적 값 반환 */
    return sum;
}