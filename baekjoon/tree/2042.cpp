#include <iostream>
typedef long long ll ;
const int MAX_N = 1000000 ;
int N, M, K ;
ll SUM = 0 ;
ll NUM[MAX_N+1] ;

ll
sum_interval (int from, int to){
  ll sum = 0 ;
  for(int x = from ; x <= to; x++){
    sum += NUM[x] ;
  }
  return sum ;
}
int 
main () {
  int a, b ;
  ll c , sum ;
  scanf("%d %d %d", &N, &M, &K) ;
  for(int i = 1 ; i <= N ; i++){
    scanf("%lld",&NUM[i]) ;
    SUM += NUM[i] ;
  }
  for(int i = 0 ; i < M+K ; i++){
    scanf("%d %d %lld", &a, &b, &c) ;
    if(a == 1){
      SUM += c - NUM[b] ;
      NUM[b] = c ;
    }
    else{
      if(c-b+1 < N/2){
        sum = sum_interval(b,c) ;
      }
      else{
        sum = SUM - sum_interval(1,b-1) - sum_interval(c+1,N) ;
      }
      printf("%lld\n", sum) ;
    }
  }
}