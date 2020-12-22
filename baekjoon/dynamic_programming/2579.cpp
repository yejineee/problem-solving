#include <iostream>
#include <algorithm>
using namespace std ; 

const int MAX_N = 300 ; 
int stair[MAX_N+1] ;
int sum[3][MAX_N+1] ; // [0]: O-O, [1]: X-O, [2]: O-X-O
int N ;

void go_up_stair(){
  for(int i = 0 ; i <= 2 ; i++){
    sum[i][N] = stair[N] ; 
  }
  sum[0][N-1] = sum[0][N] + stair[N-1] ; 
  sum[1][N-1] = sum[1][N] ;
  sum[2][N-1] = sum[2][N] ;

  for(int i = N-1 ; i >= 2 ; i--){
    if(i == N-1){
      sum[2][i-1] = sum[2][i] + stair[i-1] ;
    }
    else{
      sum[0][i-1] = max(sum[0][i-1], sum[2][i] + stair[i-1]) ;
    }
    sum[1][i-1] = max(sum[1][i-1], sum[0][i]) ; 
    sum[1][i-1] = max(sum[1][i-1], sum[2][i]) ; 
    sum[2][i-1] = max(sum[2][i-1], sum[1][i] + stair[i-1]) ; 
  }
}

int main(){
  int result[3] ;
  scanf("%d", &N) ; 
  for(int i = 1; i <= N ; i++){
    scanf("%d", &stair[i]) ; 
  }
  go_up_stair() ; 
  for(int i = 0 ; i <= 2 ; i++){
    result[i] = sum[i][1] ; 
  }
  printf("%d", *max_element(result, result+3)) ;
  return 0 ;
}
