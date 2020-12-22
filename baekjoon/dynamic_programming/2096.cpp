#include <iostream>
#include <algorithm>
#include <array>
using namespace std ;

array<int, 3> score ;
array<int, 3> min_table ;
array<int, 3> max_table ;
array<int, 3> max_tmp ;
array<int, 3> min_tmp ;
int MAX_S = 0 ;
int MIN_S = 999999 ;
int N ;


int 
main () {
  scanf("%d", &N) ;
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < 3 ; x++){
      scanf("%d", &score[x]) ;
    }
    if(y == 0){
      for(int x = 0 ; x < 3 ; x++){
        min_tmp[x] = score[x] ;
        max_tmp[x] = score[x] ;
      }
    }
    else{
      for(int x = 0 ; x < 3 ; x++){
        min_table[x] = min(MIN_S, min_tmp[x] + score[x]) ;
        max_table[x] = max(MAX_S, max_tmp[x] + score[x]) ;

        if(x+1 < 3) {
          min_table[x] = min(min_table[x], min_tmp[x+1] + score[x]) ;
          max_table[x] = max(max_table[x], max_tmp[x+1] + score[x]) ;
        }
        if(x-1 >= 0) { 
          min_table[x] = min(min_table[x], min_tmp[x-1] + score[x]) ;
          max_table[x] = max(max_table[x], max_tmp[x-1] + score[x]) ;
        }
      }
        min_table.swap(min_tmp) ;
        max_table.swap(max_tmp) ;
    }
  }
  for(int x = 0 ; x < 3 ; x++){
    MIN_S = min(MIN_S, min_tmp[x]) ;
    MAX_S = max(MAX_S, max_tmp[x]) ;
  }
  printf("%d %d\n", MAX_S, MIN_S) ;

}