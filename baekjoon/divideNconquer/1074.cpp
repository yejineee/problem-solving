

#include <iostream>
#include <cmath>

int N, R, C ;

int 
divide (int r, int c, int len){
  if(len <= 1) return 0 ;
  
  int half_len = len / 2 ;
  if( r < half_len && c < half_len){     // 1
    return divide(r, c, half_len) ;
  }
  else if(r < half_len && c >= half_len){ // 2
	  return pow(half_len, 2) + divide(r, c-half_len, half_len) ;
  }
  else if(r >= half_len && c < half_len){ // 3
    return pow(half_len, 2) * 2 + divide(r-half_len, c, half_len) ;
  }
  else if(r >= half_len && c >= half_len){ // 4
    return pow(half_len, 2) * 3 + divide(r-half_len, c-half_len , half_len) ;
  }
  
}

int 
main (void) {

  scanf("%d %d %d", &N, &R, &C) ;
  printf("%d\n",divide(R, C, pow(2,N) ) ) ;

}





