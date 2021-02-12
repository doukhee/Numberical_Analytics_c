#include <stdio.h>
#include <math.h>

double Taylor_Exp(int, double, double);

int main(){
    int n;
    double a, x;
    printf("차수 n은 ? ");
    scanf("%d", &n);
    printf("\r\n a와 x값은 ? ");
    scanf("%lf %lf", &a, &x);
    printf("\r\nn=%d\tExp(%.lf)=%lf\r\n", n, x, Taylor_Exp(n, a, x));
    return 0;
}

double Taylor_Exp(int n, double a, double x){

    int k, j;
    double sum = 0., fact;

    for(k = 0; k <= n; k++){
        fact = 1;
        for(j = 1; j <= k; j++){
            fact = fact * j;
        }
        sum = sum + exp(a) * pow(x - a, k) / fact;
    }
    return sum;
}