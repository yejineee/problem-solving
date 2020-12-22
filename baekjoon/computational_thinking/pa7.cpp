#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std ;

const int MAX_N = 500 ; 
const int INF = 999999999 ;
const int UNVISIT = -1 ;
int top_level = 0 ;
int altitude[MAX_N][MAX_N] ; 
int sum_diff[MAX_N][MAX_N] ; 
int N ; 

typedef struct{
  int y, x;
}DIR ;

DIR next_dir[4] = {{1,0} , {-1,0}, {0,1}, {0,-1}} ;

void init(int m[MAX_N][MAX_N], int n){  //memset으로 더 간단히..! 
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
      m[y][x] = n ; 
    }
  }
}

void find_dst(int start_y, int start_x){
  int y = start_y ; 
  int x = start_x ; 
  int alt = altitude[y][x] ;

  if(sum_diff[y][x] == UNVISIT) sum_diff[y][x] = 0 ;

  for(int i = 0 ; i < 4 ; i++){
    int next_y = y + next_dir[i].y ;
    int next_x = x + next_dir[i].x ;
    if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < N){
      int next_alt = altitude[next_y][next_x] ;

      if(next_alt < alt){
        if(sum_diff[next_y][next_x] == UNVISIT) find_dst(next_y, next_x) ;
        int diff = (alt - altitude[next_y][next_x]) + sum_diff[next_y][next_x] ; 
        sum_diff[y][x] = max(sum_diff[y][x], diff) ; 
      }
    }
  }
}

int main(){
  scanf("%d", &N) ; 
  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
      scanf("%d", &altitude[y][x]) ;
    }
  }

  init(sum_diff, UNVISIT) ;

  for(int y = 0 ; y < N ; y++){
    for(int x = 0 ; x < N ; x++){
      find_dst(y, x) ; 
      top_level = max(top_level, sum_diff[y][x]) ; 
    }
  }

  printf("%d", top_level) ; 
  return 0 ;
}