#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
using namespace std ; 
const int MAX = 500 ;
int R, C ; 
int height[MAX+1][MAX+1] ; 
int path[MAX+1][MAX+1] ; 
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}} ;



int count_path(int cur_r, int cur_c){ 
  if(cur_r == R && cur_c == C){
    path[R][C] = 1 ;  
  }
  else{
    if(path[cur_r][cur_c] == -1) path[cur_r][cur_c] = 0 ;

    for(int i = 0 ; i < 4 ; i++){
      int next_r = cur_r + dir[i][0] ;
      int next_c = cur_c + dir[i][1] ;
      if(1 <= next_r && next_r <= R && 1 <= next_c && next_c <= C){
        if(height[cur_r][cur_c] > height[next_r][next_c]){
          if(path[next_r][next_c] == -1){
            path[next_r][next_c] = count_path(next_r, next_c) ;
          }
          path[cur_r][cur_c] += path[next_r][next_c] ; 
        }
      }
    }
  }
  return path[cur_r][cur_c] ; 
}
int main(){
  scanf("%d %d", &R, &C) ; 
  for(int r = 1 ; r <= R ; r++){
    for(int c = 1 ; c <= C ; c++){
      scanf("%d", &height[r][c]) ;
    }
  }
  for(int i = 1 ; i <= R ; i++){
    fill(path[i]+1, path[i]+C+1, -1) ; 
  }

  count_path(1,1) ; 
  printf("%d", path[1][1]) ; 
}