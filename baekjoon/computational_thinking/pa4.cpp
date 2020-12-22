#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std ;
const int n_rod = 3 ;
const int MAX_N = 50 ; 
int N, k ;
long long n_move = 0 ; 
int disk[MAX_N+1] ; 

void hanoi(int size, int src , int dst){
  int other = 6-src-dst ; 
  if(size == 0 ) return ; 
  if(src != dst){
    hanoi(size-1, disk[size-1], other) ;
    n_move += pow(2,size-1) -1;
    n_move += 1 ;
  }
  else{
    hanoi(size-1, disk[size-1], dst) ; 
  }
}
int main () {
  int n_disk, size ; 
  scanf("%d %d", &N, &k) ;

  for(int rod = 1 ; rod <= n_rod ; rod++){
    scanf("%d", &n_disk) ;
    for(int i = 0 ; i < n_disk ; i++){
      scanf("%d", &size) ; 
      disk[size] = rod ; 
    }
  } 
  hanoi(N, disk[N], k) ; 
  printf("%lld", n_move) ;
  return 0 ;
}
