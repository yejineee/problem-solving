

#include <iostream>
#include <cmath>

int N, R, C ;

int 
divide (int r, int c, int len, int sum){
  if(len < 2) return sum ;
  
  int half_len = len / 2 ;
  if( r < half_len && c < half_len){     // 1
    if(r == 0 && c == 0){sum += 0 ; return sum;}
    else if(r == 0 && c == 1) {sum += 1 ; return sum;}
    else if(r == 1 && c == 0) {sum += 2 ; return sum;}
    else if(r == 1 && c == 1) {sum += 3 ; return sum;}
  }
  else if(r < half_len && c >= half_len){ // 2
    sum += pow(half_len, 2) ;
    c -= half_len ; 
  }
  else if(r >= half_len && c < half_len){ // 3
    sum += pow(half_len, 2) * 2 ;
    r -= half_len ;
  }
  else if(r >= half_len && c >= half_len){ // 4
    sum += pow(half_len, 2) * 3 ;
    r -= half_len ;
    c -= half_len ;
  }
  sum = divide(r, c, half_len, sum) ;
  return sum;
}

int 
main (void) {

  scanf("%d %d %d", &N, &R, &C) ;
  printf("%d\n",divide(R, C, pow(2,N), 0) ) ;

}





