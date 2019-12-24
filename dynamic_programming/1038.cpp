#include <iostream>
#include <list>
#include <math.h>
using namespace std ;

list<long long> basis ; 
list<long long> appended_basis ; 
int N ;

long long decreasing_number(){
  int digit_of_basis = 1 ;
  int order = 10 ; 
  int prefix = 1 ; 
  list<long long>::iterator it = basis.begin() ; 

  while(it != basis.end()){
    long long num_basis = *it ; 
    int prefix_of_basis = num_basis / pow(10, digit_of_basis-1) ; 
    if(prefix_of_basis == 9){
      appended_basis.swap(basis) ; 
      appended_basis.clear() ;
      digit_of_basis += 1 ;
      prefix = digit_of_basis ; 
      it = basis.begin() ; 
      continue ; 
    }

    if(prefix > prefix_of_basis){
      long long new_num = num_basis + prefix*pow(10, digit_of_basis) ;
      if(order == N){
        return new_num ; 
      }
      if(new_num == 9876543210){
        return -1 ; 
      }
      appended_basis.push_back(new_num) ; 
      it++ ;
      order += 1 ;
    }
    else{
      prefix += 1 ;
      it = basis.begin() ; 
    }
  }
}

int main(){
  scanf("%d", &N) ;
  if(N >= 0 && N <= 9){
    printf("%d", N) ;
  }
  else{
    for(int num = 0 ; num <= 9 ; num++){
      basis.push_back(num) ; 
    }
    printf("%lld", decreasing_number()) ;
  }
}
