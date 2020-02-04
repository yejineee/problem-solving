#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <list>
using namespace std ; 
const int MAX_N = 300 ; 
int n_ice = 0 ;
int iceberg[MAX_N+1][MAX_N+1] ;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} ;
int col, row ; 
void copy_iceberg(int to[MAX_N+1][MAX_N+1], int from[MAX_N+1][MAX_N+1]){
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      to[r][c] = from[r][c] ;
    }
  }
}

bool is_divided(){
  list<pair<int, int > > q ; 
  int n_connect = 0 ;
  bool visit[MAX_N+1][MAX_N+1] ; 
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      visit[r][c] = false ;
    }
  }
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      if(iceberg[r][c] > 0){
        q.push_back(make_pair(r, c)) ;
        visit[r][c] = true ; 
        while(!q.empty()){
          int cur_r = q.front().first ; 
          int cur_c = q.front().second ; 
          q.pop_front() ; 
          n_connect += 1 ;
          for(int i = 0 ; i < 4 ; i++){
            int next_r = cur_r + dir[i][0] ;
            int next_c = cur_c + dir[i][1] ;
            if(1 <= next_r && next_r <= row && 1 <= next_c && next_c <= col){
              if(iceberg[next_r][next_c] > 0 && !visit[next_r][next_c]){
                q.push_back(make_pair(next_r, next_c)) ;
                visit[next_r][next_c] = true ; 
              }
            }
          }
        }
        if(n_ice != n_connect){
          return true ; 
        }
        return false ; 
      }
    }
  }
  return false ; 
}

int count_until_division(){
  int years = 0 ;
  int new_iceberg[MAX_N+1][MAX_N+1] ; 

  while(!is_divided()){
    years += 1 ; 
    copy_iceberg(new_iceberg, iceberg) ; 
    for(int r = 1 ; r <= row ; r++){
      for(int c = 1 ; c <= col ; c++){
        if(iceberg[r][c] > 0){
          int n_water = 0 ;
          for(int i = 0 ; i < 4 ; i++){
            int next_r = r + dir[i][0] ;
            int next_c = c + dir[i][1] ;
            if(1 <= next_r && next_r <= row && 1 <= next_c && next_c <= col){
              if(iceberg[next_r][next_c] == 0){
                n_water += 1 ; 
              }
            }
          }
          new_iceberg[r][c] = max(new_iceberg[r][c] - n_water, 0) ; 
          if(new_iceberg[r][c] == 0){
            n_ice -= 1 ; 
          }
        }
      }
    }
    if(n_ice == 0){
      return 0 ;
    }
    copy_iceberg(iceberg, new_iceberg) ; 
  }
  return years ;
}

int main(){
  scanf("%d %d", &row, &col) ; 
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      scanf("%d", &iceberg[r][c]) ; 
      if(iceberg[r][c] > 0){
        n_ice += 1 ; 
      }
    }
  }
  printf("%d", count_until_division()) ; 
  return 0 ;
}