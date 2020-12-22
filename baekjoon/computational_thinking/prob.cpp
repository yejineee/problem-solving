#include <iostream>
#include <math.h>
#define MAXSIZE 100
#define FALSE 0
long long comb(int n, int k){
    long long com, c1, c2;
    long long DP[MAXSIZE][MAXSIZE] = {FALSE,};
    
    if( k == 0 || n == k )
        com = 1;
    if( k >= 1 && k <= n-1 ){
        if(DP[n-1][k-1] == FALSE) c1 = comb(n-1,k-1);
        else c1 = DP[n-1][k-1];
        if(DP[n-1][k] == FALSE) c2 = comb(n-1,k);
        else c2 = DP[n-1][k];
        com = c1 + c2;
    }
    DP[n][k] = com;
    return DP[n][k];
}
int main()
{
double p = 0.2 ;
double np = 0.8 ;
for(int N = 20 ; N <= 30; N++){
    double prob = 0 ; 
    for(int i = 11 ; i <= N ; i++){
        //printf("i : %d, N-i : %d\n",i, N-i) ;
        prob += (double)comb(N,i) * pow(p,i) * pow(np,N-i) ;
       // printf("prob : %Lf\n", prob) ;
    }
    printf(" N :%d -> %f\n",N, prob) ;
}
}

