#include <iostream>
#include <math.h>
using namespace std ; 


int main(){
  int N ; 
  scanf("%d", N) ;
  for(int i = 0 ; i < N ; i++){
    printf("%3d", i+1) ;
  }
  printf("\n") ;
  for(int k = 1 ; k <= N ; k++){
    for(int i = 1 ; i <= N ; i++){
      if(i <= pow(2,k-1)){
        if(i + pow(2,k-1) <= N){
          
        }
        else return 0 ;
      }
    }
  }
}