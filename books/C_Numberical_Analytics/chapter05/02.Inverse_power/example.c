#include <stdio.h>
#include <math.h>

double A[50][51], B[50][50], x[50];
void gauss(int MatrixSize);   
void Inverse_Power(int MatrixSize, int Max, double alpha, double eps);

int main(){
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

void Inverse_Power(int n, int Max, double alpha, double esp)
{
    int i, j, k;    
    double y[50], beta, eigval, eta, sum, back_eigval = 0.;

    for(k=1; k<=Max; k++ ){
       printf("\nk = %d \n", k);
       for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                A[i][j]=B[i][j];
            }
	        A[i][i]=A[i][i]-alpha;
	        A[i][n]=x[i];
        }

       gauss(n);
       for(i=0; i<n; i++){
           y[i]=A[i][n];
       }
       sum=0.;
       for(i=0;i<n;i++){
           sum=sum+x[i]*y[i];
       }
       beta=sum;

       sum=0.;
       for(i=0;i<n;i++){
           sum=sum+y[i]*y[i];
       }
       eta=pow(sum, 0.5);

       eigval=1/beta + alpha;
       printf("\t고유치는 : %lf \n", eigval);
       printf("\r\n고유 벡터는 ?");
       for(i=0;i<n;i++){
           printf("%lf \t", x[i]=y[i]/eta);
       }
       if( fabs(eigval - back_eigval) < esp){
           return;
       }
       back_eigval = eigval;
    }
    return;
}

void gauss(int MatrixSize){
    int i, j, k;
    double temp;
    for(j=0; j<MatrixSize; j++){
       if(A[j][j]==0){
           for(i=j+1; i<MatrixSize; i++){
	            if(A[i][j]!=0){
		            for(k=j; k<MatrixSize+1; k++){
		                temp=A[j][k];   
		                A[j][k]=A[i][k];
		                A[i][k]=temp;
		            }
		            break;
	            }
	        }
       }
       if(A[j][j]==0){
	        printf("\\n\n     Matrix is singular!        \n\n");
	        return;
       }
       for(i=j+1; i<MatrixSize; i++){
       	    for(k=j+1; k<MatrixSize+1; k++){
                A[i][k]=A[i][k]-(A[i][j]/A[j][j])*A[j][k];
            }
        }
    }

    for(i=MatrixSize-1; i>=0; i--){
       for(k=i+1; k<MatrixSize; k++){
           A[i][MatrixSize]=A[i][MatrixSize]-A[i][k]*A[k][MatrixSize];
       }
       A[i][MatrixSize]=A[i][MatrixSize]/A[i][i];
    }
    return;
}




