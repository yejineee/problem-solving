#include <iostream>
using namespace std ; 
const int MAX_N = 100 ; 
long long seq[MAX_N+1] ; 

long long padovan(int n){
  if(n >= 1 && n <= 3){
    seq[n] = 1 ; 
  }
  else{
    if(seq[n-2] == 0){
      seq[n-2] = padovan(n-2) ; 
    }
    if(seq[n-3] == 0){
      seq[n-3] = padovan(n-3) ; 
    }
    seq[n] = seq[n-2] + seq[n-3] ;
  }
  return seq[n] ; 
}

int main(){
  int T, N ; 
  scanf("%d", &T) ; 
  while(T--){
    scanf("%d", &N) ; 
    printf("%lld\n",padovan(N)) ; 
  }

}