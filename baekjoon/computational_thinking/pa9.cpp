#include <iostream>
#include <stdio.h>
const int MAX_N = 500 ; 
const int INF = 999999999 ; 
int N ; 
int interval_time[MAX_N+1][MAX_N+1] ;
int cum_sum[MAX_N+1] ; 


int main(){
  scanf("%d", &N) ; 

  for(int i = 1 ; i <= N ; i++){
    int len ;
    scanf("%d", &len) ; 
   // interval_time[1][i] = len ; 
    cum_sum[i] = cum_sum[i-1] + len ;
  }

  for(int interval = 2 ; interval <= N ; interval++){
    for(int i = 1 ; i <= N-interval+1 ; i++){
      int j = i + interval - 1 ;
      interval_time[i][j] = INF ; 
      for(int k = i ; k <= j-1 ; k++){
        int q = interval_time[i][k] + interval_time[k+1][j] + cum_sum[j]-cum_sum[i-1];
        if(q < interval_time[i][j]){
          interval_time[i][j] = q ; 
        }
      } 

    }
  }

  printf("%d", interval_time[1][N]) ;

}