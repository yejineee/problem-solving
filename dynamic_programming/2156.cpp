#include <iostream>
#include <algorithm>
using namespace std ;

const int MAX_N = 10000 ; 
int sum_wine[4][MAX_N+1] ; // [0]: O-X, [1]: O-O, [2]: X-O, [3]: X-X

int main(){
  int N ; 
  int wine[MAX_N+1] ;
  int result[4] ; 

  scanf("%d", &N) ;
  for(int i = 1 ; i <= N ; i++){
    scanf("%d", &wine[i]) ; 
  }
  sum_wine[0][N] = wine[N] ;
  sum_wine[1][N] = wine[N] ;

  for(int i = N ; i >= 2 ; i--){
    sum_wine[1][i-1] = sum_wine[0][i] + wine[i-1] ; 
    sum_wine[2][i-1] = sum_wine[0][i] ; 
    sum_wine[2][i-1] = max(sum_wine[2][i-1], sum_wine[1][i]); 
    sum_wine[0][i-1] = max(sum_wine[0][i-1], sum_wine[2][i] + wine[i-1]) ; 
    sum_wine[0][i-1] = max(sum_wine[0][i-1], sum_wine[3][i] + wine[i-1]) ; 
    sum_wine[3][i-1] = max(sum_wine[3][i-1], sum_wine[2][i]) ; 
  }

  for(int i = 0 ; i < 4 ; i++){
    result[i] = sum_wine[i][1] ;
  }
  printf("%d", *max_element(result, result+4)) ; 
  return 0 ;
}