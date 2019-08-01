#include <iostream>
#include <algorithm>
#include <array>
using namespace std ;

int score[100000][3] ;
array<int, 3> pre_table ;
array<int, 3> post_table ;
int MAX_S = 0 ;
int MIN_S = 999999 ;
int N ;

void
fill_table(int n, array<int, 3> &table){
  for(int x = 0 ; x < 3 ; x++){
    table[x] = n ;
  }
}
void 
find_min (){
  int y = 1 ;
  int cur_score ;
  while(y < N){
    for(int x = 0 ; x < 3 ; x++){
      cur_score = score[y][x] ;
      post_table[x] = min(post_table[x], pre_table[x] + cur_score ) ;
      if(x-1 >= 0) post_table[x] = min(post_table[x], pre_table[x-1] + cur_score ) ;
      if(x+1 < 3)  post_table[x] = min(post_table[x], pre_table[x+1] + cur_score ) ;
    }
    y += 1 ;
    pre_table.swap(post_table) ;
    fill_table(MIN_S, post_table) ;
  }
  for(int x = 0 ; x < 3 ; x++){
    MIN_S = min(MIN_S,pre_table[x]) ;
  }
}

void 
find_max (){
  int y = 1 ;
  int cur_score ;
  while(y < N){
    for(int x = 0 ; x < 3 ; x++){
      cur_score = score[y][x] ;
      post_table[x] = max(post_table[x], pre_table[x] + cur_score ) ;
      if(x-1 >= 0) post_table[x] = max(post_table[x], pre_table[x-1] + cur_score ) ;
      if(x+1 < 3)  post_table[x] = max(post_table[x], pre_table[x+1] + cur_score ) ;
    }
    y += 1 ;
    pre_table.swap(post_table) ;
    fill_table(MAX_S, post_table) ;
  }
  for(int x = 0 ; x < 3 ; x++){
    MAX_S = max(MAX_S,pre_table[x]) ;
  }
}

int 
main () {
  scanf("%d", &N) ;
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < 3 ; x++){
      scanf("%d", &score[y][x]) ;
    }
  }
  for(int x = 0 ; x < 3 ; x++){
    pre_table[x] = score[0][x] ;
  }
  fill_table(MIN_S, post_table) ;
  find_min() ;

  for(int x = 0 ; x < 3 ; x++){
    pre_table[x] = score[0][x] ;
  }
  fill_table(MAX_S, post_table) ;
  find_max() ;

  printf("%d %d\n", MAX_S, MIN_S) ;

}