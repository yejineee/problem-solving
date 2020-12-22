#include <iostream>
#include <utility>
#include <list>
#include <unistd.h>
using namespace std ; 

const int MAX_LEN = 1000 ; 
int box[MAX_LEN+1][MAX_LEN+1] ; 
int row, col ; 
int n_unripen = 0 ; 
list<pair<int, int> > ripen ; 
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}} ; 

int find_min_days(){
  int days = 0 ;
  if(n_unripen == 0){
    return 0 ; 
  }
  while(!ripen.empty() && n_unripen != 0){
    days += 1 ; 
    int n_ripen = ripen.size() ; 
    for(int n = 0 ; n < n_ripen; n++){
      int r = ripen.front().first ;
      int c = ripen.front().second ; 
      ripen.pop_front() ; 
      for(int i = 0 ; i < 4 ; i++){
        int next_r = r+dir[i][0] ; 
        int next_c = c+dir[i][1] ; 
        if( 1 <= next_r && next_r <= row && 1 <= next_c && next_c <= col){
          if(box[next_r][next_c] == 0){
            box[next_r][next_c] = 1 ; 
            n_unripen -= 1 ; 
            ripen.push_back(make_pair(next_r, next_c)) ; 
          }
        }
      }
    }
  }
  if(n_unripen != 0){
    return -1 ; 
  }
  return days ; 
}

int main(){
  scanf("%d %d", &col, &row) ; 
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      int status ; 
      scanf("%d" , &status) ; 
      if(status == 1){
        ripen.push_back(make_pair(r,c)) ; 
      }
      else if(status == 0){
        n_unripen += 1 ; 
      }
      box[r][c] = status ; 
    }
  }
  printf("%d", find_min_days()) ; 
}