#include <stdio.h>

int main(){
    /** */
    float sum1 = 1.0, sum0 = 0.0, dif = 0.000001;
    /** */
    double dsum1 = 1.0, dsum0 = 0.0, ddif = 0.000001;
    /** */
    for(int i = 1; i <= 10000; i++){
        /** */
        sum1 = sum1 + dif;
        /** */
        dsum1 = dsum1 + ddif;
        /** */
        sum0 = sum0 + dif;
        /** */
        dsum0 = dsum0 + ddif;
    }
    /** */
    printf("Sum1 = %f, Sum0 = %f\r\n", sum1 , sum0 + 1.0);
    /** */
    printf("dSum1 = %f, dSum0 = %f\r\n", dsum1 , dsum0 + 1.0);
    return 0;
}