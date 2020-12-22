#include <iostream>
using namespace std ; 
const int MAX_N = 40 ;
int T, N; 
int call_0[MAX_N+1], call_1[MAX_N+1] ; 
long long fibonacci[MAX_N+1] ; 

long long fib(int n){
  if(fibonacci[n] != 0) return fibonacci[n] ; 
  if(n == 0){
    fibonacci[n] = 0 ;
    call_0[0] = 1 ;
    call_1[0] = 0 ;
    return 0 ; 
  }
  if(n == 1){
    fibonacci[n] = 1 ;
    call_0[1] = 0 ;
    call_1[1] = 1 ;
    return 1 ;     
  }
  fibonacci[n] = fib(n-1) + fib(n-2) ; 
  call_0[n] = call_0[n-1] + call_0[n-2] ;
  call_1[n] = call_1[n-1] + call_1[n-2] ;
  return fibonacci[n] ;
}
int main(){
  scanf("%d", &T) ; 
  while(T--){
    scanf("%d", &N) ;
    fib(N) ; 
    printf("%d %d\n",call_0[N], call_1[N]) ;
  }
  return 0 ; 
}