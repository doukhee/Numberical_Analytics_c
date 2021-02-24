#include <stdio.h>

/**
 * 1 + 1/2^n > 1 이 되는 최소의 수 1/2^n을 구하는 기게오차를 추정해보자
 */

int main(){
    /** */
    //float body = 2, test = 1, meps;
    double body = 2, test = 1, meps;
    /** body 값이 1보다 크지 않을 때까지 반복 */
    for(; body > 1. ; ){
        /** */
        test = test / 2;
        /** */
        body = 1 + test;
    }
    /** 기계적 오차를 출력 */
    /** 1보다 크지 않으면, 그 직전 meps 출력 */
    printf("machine epsilon = %16.8e\r\n", 2 * meps);
    return 0;
}