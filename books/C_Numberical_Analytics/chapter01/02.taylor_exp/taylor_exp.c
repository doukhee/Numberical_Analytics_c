#include <stdio.h>
#include <math.h>
/** 
 * 테일러 급수란 여러 번 미분가능한 함수 f(x)f(x)에 대해 x=ax=a에서 그 f(x)f(x)에 접하는 다항함수로 표현하는 방법이라고 할 수 있다. 
 * 특히 x=0x=0에서의 테일러 전개는 자주 사용되며, 이를 특별히 매클로린 급수(Maclaurin Series)라고도 부른다.
 * 테일러 정리를 이용해 함수를 근사할 수 있단 점은 무한히 미분가능한(smooth) 실함수의 테일러 급수와 주어진 함수가 같단 것을 의미하진 않는다.
 * 테일러 다항식의 차원을 계속 확장시켜도 다항식의 값은 전혀 생뚱맞은 값을 가지고 오차항이 사라지지 않을 수 있다! 대표적인 예로 x>0x>0에서는 e^{-1/x}e −1/x로, 
 * 나머지에서는 00으로 정의된 함수를 들 수 있는데, 이 함수를 00에서 테일러 전개하면 언제나 0이 나온다. 테일러 급수가 그 급수를 만드는 데 사용된 함수와 같아지는 함수는 특별히 해석함수(analytic function)이라고 부른다.
 */
/**
 * f(a) + (x-a)f'(a) + (x-a)^2 / 2! * f''(a) + ... + (x-a)^n / n! * f^(n)(a)를 테일러 급수라고 한다
 */
double Taylor_Exp(int, double, double);

int main(){
    /** 차수를 저장할 변수 선언 */
    int n;
    /** */
    double a, x;
    /** 차수를 입력을 안내하기 위한 printf문 */
    printf("차수 n은 ? ");
    /** 차수를 stdin으로 입력을 받는다 */
    scanf("%d", &n);
    /** a, b를 입력을 안내하기 위한 printf문 */
    printf("\r\n a와 x값은 ? ");
    /** 값을 입력 받기 */
    scanf("%lf %lf", &a, &x);
    /** 차수와 테일러 급수를 printf로 출력 */
    printf("\r\nn=%d\tExp(%.lf)=%lf\r\n", n, x, Taylor_Exp(n, a, x));
    
    return 0;
}
/** 테일러 급수를 구하기 위한 함수 */
double Taylor_Exp(int n, double a, double x){
    /** 합과 펙토리얼 값을 담기 위한 변수 */
    double sum = 0., fact;
    /** 테일러 급수를 전개하기 위한 반복문 */
    for(int k = 0; k <= n; k++){
        /** 펙토리얼 최소 값인 1인 값 선언 */
        fact = 1;
        /** 펙토리얼 계산 */
        for(int j = 1; j <= k; j++){
            /** 펙토리얼 계산 진행 */
            fact = fact * j;
        }
        /** 
         * pow(double a, double b) - a^b의 값을 반환하는 a의 b제곱의 값을 반환하는 함수
         * exp(double) - 자연 지수 함수를 계산하는 함수 반환 값으로 double 형이다
         */
        /**
         * Taylor : sum = e^a * (x-a)^k / fact
         */
        sum = sum + exp(a) * pow(x - a, k) / fact;
    }
    /** 합을 반환 */
    return sum;
}