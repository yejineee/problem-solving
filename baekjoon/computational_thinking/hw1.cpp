#include <iostream>
#include <stdlib.h>
using namespace std ;
const int MAX_N = 10 ;
int M[MAX_N][MAX_N] ;
int N ;

void
insertion_sort() {
  int p, q, key;
  for(p = 1 ; p < N ; p++){
    key = M[0][p] ;
    for(q = p-1 ; q >= 0 && M[0][q] > key ; q--){
      M[0][q+1] = M[0][q] ;
    }
    M[0][q+1] = key ;
  }
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main () {
  scanf("%d", &N) ;
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
      scanf("%d", &M[y][x]) ;
    }
  }
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
      printf("%3d",M[y][x]) ;
    }
    printf("\n") ;
  }

  mergesort(M, N, sizeof(int),compare) ;
  for(int y = 1 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
      if(M[0][0] < M[y][x]){
        M[0][0] = M[y][x] ;
        mergesort(M, N, sizeof(int),compare) ;
      }
    }
  }
  printf("-----------------------\n") ;
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
        printf("%5d",M[y][x]) ;
    }
    printf("\n") ;
  }
}