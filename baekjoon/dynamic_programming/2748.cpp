#include <iostream>
using namespace std ; 
const int MAX_N = 90 ;
int N ; 
long long fibonacci[MAX_N+1] ; 

long long fib(int n){
  if(fibonacci[n] != 0) return fibonacci[n] ; 
  if(n == 0){
    fibonacci[n] = 0 ;
    return 0 ; 
  }
  if(n == 1){
    fibonacci[n] = 1 ;
    return 1 ;     
  }
  fibonacci[n] = fib(n-1) + fib(n-2) ; 
  return fibonacci[n] ;
}
int main(){
  scanf("%d", &N) ; 
  printf("%lld", fib(N)) ; 
  return 0 ; 
}