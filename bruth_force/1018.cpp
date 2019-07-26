#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

const int MAX = 50 ;
const int BLACK = 1 ;
const int WHITE = -1 ;
char board[MAX][MAX] ;
int N, M ;

int 
check (int _y , int _x , int flag){
  int change = 0 ; 
  for(int y = _y ; y < _y+8 ; y++){
    for(int x = _x ; x < _x+8 ; x++){
      if(flag == BLACK){
        if(board[y][x] != 'B') {change += 1 ;}
      }
      if(flag == WHITE){
        if(board[y][x] != 'W') {change += 1 ;}
      }
      flag *= (-1) ;
    }
    flag *= (-1) ;
  }
  return change ;
}
int 
main () {
  int min_n = -1 ;
  scanf("%d %d", &N, &M) ;
  for(int y = 0 ; y < N ; y++){
    scanf("%s",board[y]) ; 
  }
  for(int y = 0 ; y+7 < N ; y++){
    for(int x = 0 ; x+7 < M ; x++){
      if(min_n == -1) min_n = min(check(y, x, BLACK), check(y, x, WHITE)) ;
      else{
        min_n = min(min_n, check(y, x, BLACK)) ;
        min_n = min(min_n, check(y, x, WHITE)) ;
      }
    }
  }
  printf("%d\n",min_n) ;
}