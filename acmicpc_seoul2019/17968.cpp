#include <iostream>
#include <string.h>
using namespace std ; 

int A[1001] ;
int N ; 
int SIZE = 1000 ; 

int main(){
  bool min_num[SIZE] ; 
  scanf("%d", &N) ;
  A[0] = 1 ; 
  A[1] = 1 ;
  A[2] = 2 ;
  for(int i = 3 ; i <= N ; i++){
    memset(min_num, 1, sizeof(bool)*SIZE) ;
    for(int k = 1 ; k <= i/2 ; k++){
      int impossible_min = 2*A[i-k] - A[i-2*k] ;
      min_num[impossible_min] = false ; 
    }
    for(int n = 1 ; n <= SIZE ; n++){
      if(min_num[n] == true){
        A[i] = n ;  
        break ;   
      }
    }
  }
  printf("%d", A[N]) ; 
}