#include <iostream>
typedef unsigned long long ll ;

ll
permutation (int n, int m){ // nPm
  ll ret = 1 ;
  while(m--){
    ret *= n ;
    n -= 1 ;
  }
  return ret ;
}
ll
combination (int n, int m) { // nCm
  if(n-m < m){
    return permutation(n,n-m) / permutation(n-m, n-m) ;
  }
  return permutation(n,m) / permutation(m,m) ;
}

int 
main () {
  int T, N, M ;
  scanf("%d", &T) ;
  while(T--){
    scanf("%d %d", &N, &M) ;
    printf("%llu\n",combination(M, N)) ;
  }
}